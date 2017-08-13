"""
This module defines the Manager class.
"""
import atexit
from collections import deque
from threading import RLock, Thread, current_thread
from signal import SIGINT, SIGTERM, signal as set_signal_handler
from time import time
from itertools import chain, count
from heapq import heappop, heappush


from ..six import Iterator, create_bound_method, next

try:
    from signal import SIGKILL
except ImportError:
    SIGKILL = SIGTERM

TIMEOUT = 0.1  # 100ms timeout when idle


class UnregistrableError(Exception):

    """
    Raised if a component cannot be registered as child.
    """


class TimeoutError(Exception):

    """Raised if wait event timeout occurred"""


class ExceptionWrapper(object):

    def __init__(self, exception):
        self.exception = exception

    def extract(self):
        return self.exception


class Sleep(Iterator):

    def __init__(self, seconds):
        self._task = None

        try:
            self.expiry = time() + float(seconds)
        except ValueError:
            raise TypeError("a float is required")

    def __iter__(self):
        return self

    def __repr__(self):
        return "sleep({0:s})".format(repr(self.expiry - time()))

    def __next__(self):
        if time() >= self.expiry:
            raise StopIteration()
        return self

    @property
    def expired(self):
        return time() >= self.expiry

    @property
    def task(self):
        return self._task

    @task.setter
    def task(self, task):
        self._task = task


def sleep(seconds):
    """
    Delay execution of a coroutine for a given number of seconds.
    The argument may be a floating point number for subsecond precision.
    """

    return Sleep(seconds)


class _State(object):
    __slots__ = ('task', 'run', 'flag', 'event', 'timeout', 'parent', 'task_event', 'tick_handler')

    def __init__(self, timeout):
        self.task = None
        self.run = False
        self.flag = False
        self.event = None
        self.timeout = timeout
        self.parent = None
        self.task_event = None
        self.tick_handler = None


class _EventQueue(object):
    __slots__ = ('_queue', '_priority_queue', '_counter', '_flush_batch')

    def __init__(self):
        self._queue = deque()
        self._priority_queue = []
        self._counter = count()
        self._flush_batch = 0

    def __len__(self):
        return len(self._queue) + len(self._priority_queue)

    def drain_from(self, other_queue):
        self._queue.extend(other_queue._queue)
        other_queue._queue.clear()
        # Queue is currently flushing events /o\
        assert not len(other_queue._priority_queue)

    def append(self, event, priority):
        """append an event to the queue"""
        self._queue.append((priority, next(self._counter), event))

    def dispatch_events(self, dispatcher):
        if self._flush_batch == 0:
            # FIXME: Might be faster to use heapify instead of pop +
            # heappush. Though, with regards to thread safety this
            # appears to be the better approach.
            self._flush_batch = count = len(self._queue)
            while count:
                count -= 1
                heappush(self._priority_queue, self._queue.popleft())

        while self._flush_batch > 0:
            self._flush_batch -= 1  # Decrement first!
            (event, channels) = heappop(self._priority_queue)[2]
            dispatcher(event, channels, self._flush_batch)


class Manager(object):

    """
    The manager class has two roles. As a base class for component
    implementation, it provides methods for event and handler management.
    The method :meth:`.fireEvent` appends a new event at the end of the event
    queue for later execution. :meth:`.waitEvent` suspends the execution
    of a handler until all handlers for a given event have been invoked.
    :meth:`.callEvent` combines the last two methods in a single method.

    The methods :meth:`.addHandler` and :meth:`.removeHandler` allow handlers
    for events to be added and removed dynamically. (The more common way to
    register a handler is to use the :func:`~.handlers.handler` decorator
    or derive the class from :class:`~.components.Component`.)

    In its second role, the :class:`.Manager` takes the role of the
    event executor. Every component hierarchy has a root component that
    maintains a queue of events. Firing an event effectively means
    appending it to the event queue maintained by the root manager.
    The :meth:`.flush` method removes all pending events from the
    queue and, for each event, invokes all the handlers. Usually,
    :meth:`.flush` is indirectly invoked by :meth:`run`.

    The manager optionally provides information about the execution of
    events as automatically generated events. If an :class:`~.events.Event`
    has its :attr:`success` attribute set to True, the manager fires
    a :class:`~.events.Success` event if all handlers have been
    executed without error. Note that this event will be
    enqueued (and dispatched) immediately after the events that have been
    fired by the event's handlers. So the success event indicates both
    the successful invocation of all handlers for the event and the
    processing of the immediate follow-up events fired by those handlers.

    Sometimes it is not sufficient to know that an event and its
    immediate follow-up events have been processed. Rather, it is
    important to know when all state changes triggered by an event,
    directly or indirectly, have been performed. This also includes
    the processing of events that have been fired when invoking
    the handlers for the follow-up events and the processing of events
    that have again been fired by those handlers and so on. The completion
    of the processing of an event and all its direct or indirect
    follow-up events may be indicated by a :class:`~.events.Complete`
    event. This event is generated by the manager if :class:`~.events.Event`
    has its :attr:`complete` attribute set to True.

    Apart from the event queue, the root manager also maintains a list of
    tasks, actually Python generators, that are updated when the event queue
    has been flushed.
    """

    _currently_handling = None
    """
    The event currently being handled.
    """

    def __init__(self, *args, **kwargs):
        "initializes x; see x.__class__.__doc__ for signature"

        self._queue = deque()

        self._tasks = set()
        self._cache = dict()
        self._globals = set()
        self._handlers = dict()

        self._flush_batch = 0
        self._cache_needs_refresh = False

        self._executing_thread = None
        self._flushing_thread = None
        self._running = False
        self.__thread = None
        self.__process = None
        self._lock = RLock()

        self.root = self.parent = self
        self.components = set()

    def start(self):
        """
        Start a new thread or process that invokes this manager's
        ``run()`` method. The invocation of this method returns
        immediately after the task or process has been started.
        """

        self._running = True

        return self.__thread, None

    def stop(self):
        """
        Stop this manager. Invoking this method causes
        an invocation of ``run()`` to return.
        """

        self._running = False

        return None

    def run(self):
        """
        Run this manager. The method fires the
        :class:`~.events.Started` event and then continuously
        calls :meth:`~.tick`.

        The method returns when the manager's
        :meth:`~.stop` method is invoked.

        If invoked by a programs main thread, a signal handler for
        the ``INT`` and ``TERM`` signals is installed. This handler
        fires the corresponding :class:`~.events.Signal`
        events and then calls :meth:`~.stop` for the manager.
        """

        atexit.register(self.stop)

        if current_thread().getName() == "MainThread":
            try:
                set_signal_handler(SIGINT, self._signal_handler)
                set_signal_handler(SIGTERM, self._signal_handler)
            except ValueError:
                # Ignore if we can't install signal handlers
                pass

        self._running = True

        self.__thread = None
        self.__process = None

