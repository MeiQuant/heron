# encoding: UTF-8
"""
This module defines the Manager class.
"""
import atexit
from collections import deque
from threading import RLock, Thread, current_thread
from signal import SIGTERM
from time import time
from itertools import chain, count
from heapq import heappop, heappush
from multiprocessing import current_process
from os import getpid
from inspect import isfunction
from operator import attrgetter
from sys import exc_info as _exc_info, stderr
from traceback import format_exc


from ..six import Iterator, create_bound_method, next
from .events import started, stopped
from ..tools import tryimport

try:
    from signal import SIGKILL
except ImportError:
    SIGKILL = SIGTERM

TIMEOUT = 0.1  # 100ms timeout when idle

# todo refactor this method to check thread ident
thread = tryimport(("thread", "_thread"))


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

    @property
    def queue(self):
        """
        Return the Event Queue. Often used in register child.
        :return:
        """
        return self._queue

    @property
    def priority_queue(self):
        """
        Return the Priority Event Queue. Often used in register child.
        :return:
        """
        return self._priority_queue

    def drain_from(self, other_queue):
        self._queue.extend(other_queue.queue)
        other_queue._queue.clear()
        # Queue is currently flushing events /o\
        assert not len(other_queue.priority_queue)

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
            dispatcher(event, self._flush_batch)


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

        self._queue = _EventQueue()

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

    def __nonzero__(self):
        "x.__nonzero__() <==> bool(x)"

        return True

    __bool__ = __nonzero__

    def __repr__(self):
        "x.__repr__() <==> repr(x)"

        name = self.__class__.__name__

        q = len(self._queue)
        state = "R" if self.running else "S"

        pid = current_process().pid

        if pid:
            id = "%s:%s" % (pid, current_thread().getName())
        else:
            id = current_thread().getName()

        format = "<%s%s %s (queued=%d) [%s]>"
        return format % (name, id, q, state)

    def __contains__(self, y):
        """x.__contains__(y) <==> y in x

        Return True if the Component y is registered.
        """

        components = self.components.copy()
        return y in components or y in [c.__class__ for c in components]

    def __len__(self):
        """x.__len__() <==> len(x)

        Returns the number of events in the Event Queue.
        """

        return len(self._queue)

    @property
    def name(self):
        """Return the name of this Component/Manager"""

        return self.__class__.__name__

    @property
    def running(self):
        """Return the running state of this Component/Manager"""

        return self._running

    @property
    def pid(self):
        """Return the process id of this Component/Manager"""

        return getpid() if self.__process is None else self.__process.pid

    @property
    def queue(self):
        """
        Return the Event Queue. Often used in register child.
        :return:
        """
        return self._queue

    def get_handlers(self, event, **kwargs):
        """
        Get registered handlers by event
        :param event:
        :param kwargs:
        :return:
        """
        name = event.name
        handlers = set()

        _handlers = set()
        _handlers.update(self._handlers.get("*", []))
        _handlers.update(self._handlers.get(name, []))

        for _handler in _handlers:
                handlers.add(_handler)

        if not kwargs.get("exclude_globals", False):
            handlers.update(self._globals)

        for c in self.components.copy():
            handlers.update(c.get_handlers(event, **kwargs))

        return handlers

    def add_handler(self, f):
        method = create_bound_method(f, self) if isfunction(f) else f

        # add handler
        setattr(self, method.__name__, method)

        # todo remove channel

        if not method.names and method.channel == "*":
            self._globals.add(method)
        elif not method.names:
            self._handlers.setdefault("*", set()).add(method)
        else:
            for name in method.names:
                self._handlers.setdefault(name, set()).add(method)

        self.root._cache_needs_refresh = True

        return method

    def remove_handler(self, method, event=None):
        if event is None:
            names = method.names
        else:
            names = [event]

        for name in names:
            self._handlers[name].remove(method)
            if not self._handlers[name]:
                del self._handlers[name]
                try:
                    delattr(self, method.__name__)
                except AttributeError:
                    # Handler was never part of self
                    pass

        self.root._cache_needs_refresh = True

    def register_child(self, component):
        if component._executing_thread is not None:
            if self.root._executing_thread is not None:
                raise UnregistrableError()
            self.root._executing_thread = component._executing_thread
            component._executing_thread = None
        self.components.add(component)
        # drain event queue from the child component
        self.root._queue.drain_from(component.queue)
        self.root._cache_needs_refresh = True

    def unregister_child(self, component):
        self.components.remove(component)
        self.root._cache_needs_refresh = True

    def _fire(self, event, priority=0):
        # check if event is fired while handling an event
        th = (self._executing_thread or self._flushing_thread)
        if thread.get_ident() == (th.ident if th else None):
            if self._currently_handling is not None and \
                    getattr(self._currently_handling, "cause", None):
                # if the currently handled event wants to track the
                # events generated by it, do the tracking now
                event.cause = self._currently_handling
                event.effects = 1
                self._currently_handling.effects += 1

            self._queue.append(event, priority)

        # the event comes from another thread
        else:
            # Another thread has provided us with something to do.
            # If the component is running, we must make sure that
            # any pending generate event waits no longer, as there
            # is something to do now.
            with self._lock:
                # Modifications of attribute self._currently_handling
                # (in _dispatch()), calling reduce_time_left(0). and adding an
                # event to the (empty) event queue must be atomic, so we have
                # to lock. We can save the locking around
                # self._currently_handling = None though, but then need to copy
                # it to a local variable here before performing a sequence of
                # operations that assume its value to remain unchanged.
                handling = self._currently_handling

                self._queue.append(event, priority)

    def fire_event(self, event, **kwargs):
        """Fire an event into the system.

        :param event: The event that is to be fired.
        """

        self.root._fire(event, **kwargs)

        return event

    fire = fire_event

    def _flush(self):
        # Handle events currently on queue, but none of the newly generated
        # events. Note that _flush can be called recursively.
        old_flushing = self._flushing_thread
        try:
            self._flushing_thread = current_thread()
            self._queue.dispatch_events(self._dispatcher)
        finally:
            self._flushing_thread = old_flushing

    def flush_events(self):
        """
        Flush all Events in the Event Queue. If called on a manager
        that is not the root of an object hierarchy, the invocation
        is delegated to the root manager.
        """

        self.root._flush()

    flush = flush_events

    def _dispatcher(self, event):

        if event.cancelled:
            return

        if event.complete:
            if not getattr(event, "cause", None):
                event.cause = event
            event.effects = 1  # event itself counts (must be done)
        eargs = event.args
        ekwargs = event.kwargs

        if self._cache_needs_refresh:
            # Don't call self._cache.clear() from other threads,
            # this may interfere with cache rebuild.
            self._cache.clear()
            self._cache_needs_refresh = False
        try:  # try/except is fastest if successful in most cases
            event_handlers = self._cache[event.name]
        except KeyError:
            h = self.get_handlers(event)

            event_handlers = sorted(
                chain(*h),
                key=attrgetter("priority"),
                reverse=True
            )

            self._cache[event.name] = event_handlers

        self._currently_handling = event

        value = None
        err = None

        for event_handler in event_handlers:
            event.handler = event_handler
            try:
                if event_handler.event:
                    value = event_handler(event, *eargs, **ekwargs)
                else:
                    value = event_handler(*eargs, **ekwargs)
            except KeyboardInterrupt:
                self.stop()
            except SystemExit as e:
                self.stop(e.code)
            except:
                value = err = _exc_info()
                event.value.errors = True

                if event.failure:
                    self.fire(
                        event.child("failure", event, err)
                    )

                # todo raise a failure exception

            if value is not None:
                event.value = value

            if event.stopped:
                break  # Stop further event processing

        self._currently_handling = None
        self._event_done(event, err)

    def _event_done(self, event, err=None):
        if event.waitingHandlers:
            return

        # The "%s_done" event is for internal use by waitEvent only.
        # Use the "%s_success" event in your application if you are
        # interested in being notified about the last handler for
        # an event having been invoked.
        if event.alert_done:
            self.fire(event.child("done", event.value))

        if err is None and event.success:
            self.fire(
                event.child("success", event, event.value.value))

        while True:
            # cause attributes indicates interest in completion event
            cause = getattr(event, "cause", None)
            if not cause:
                break
            # event takes part in complete detection (as nested or root event)
            event.effects -= 1
            if event.effects > 0:
                break  # some nested events remain to be completed
            if event.complete:  # does this event want signaling?
                self.fire(
                    event.child("complete", event, event.value.value))

            # this event and nested events are done now
            delattr(event, "cause")
            delattr(event, "effects")
            # cause has one of its nested events done, decrement and check
            event = cause

    def start(self):
        """
        Start a new thread or process that invokes this manager's
        ``run()`` method. The invocation of this method returns
        immediately after the task or process has been started.
        """

        self.__thread = Thread(target=self.run, name=self.name)
        self.__thread.daemon = True
        self.__thread.start()

        return self.__thread, None

    def join(self):
        if self.__thread is not None:
            return self.__thread.join()

    def stop(self, code=None):
        """
        Stop this manager. Invoking this method causes
        an invocation of ``run()`` to return.
        """

        if not self.running:
            return

        self._running = False

        self.fire(stopped(self))

        if self.root._executing_thread is None:
            for _ in range(3):
                self.tick()

        if code is not None:
            raise SystemExit(code)

    def tick(self):
        """
        Execute all possible actions once. Flush the event queue.

        This method is usually invoked from :meth:`~.run`. It may also be
        used to build an application specific main loop.
        """

        if self._running:
            return
        if len(self._queue):
            self.flush()

    def run(self):
        """
        Run this manager. The method fires the
        :class:`~.events.Started` event and then continuously
        calls :meth:`~.tick`.

        The method returns when the manager's
        :meth:`~.stop` method is invoked.

        events and then calls :meth:`~.stop` for the manager.
        """

        atexit.register(self.stop)

        self._running = True
        self.root._executing_thread = current_thread()

        self.fire(started(self))

        try:
            while self.running or len(self._queue):
                self.tick()
            # Fading out, handle remaining work from stop event
            for _ in range(3):
                self.tick()
        except Exception as exc:
            stderr.write("Unhandled ERROR: {0:s}\n".format(exc))
            stderr.write(format_exc())
        finally:
            try:
                self.tick()
            except:
                pass

        self.root._executing_thread = None
        self.__thread = None
        self.__process = None

