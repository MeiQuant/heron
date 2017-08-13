# encoding: UTF-8
"""
This module defines the basic event class and common events.

"""


# todo refactor event class
class Event(object):

    value = None
    parent = None
    notify = False
    success = False
    failure = False
    complete = False
    alert_done = False
    waitingHandlers = 0

    @classmethod
    def create(cls, _name, *args, **kwargs):
        return type(cls)(_name, (cls,), {})(*args, **kwargs)

    def child(self, name, *args, **kwargs):
        e = Event.create(
            "{0:s}_{1:s}".format(self.name, name), *args, **kwargs
        )
        e.parent = self
        return e

    def __init__(self, *args, **kwargs):
        """An event is a message send to one or more components.
        It is eventually dispatched to all components
        that have handlers for one of the channels and the event type.

        All normal arguments and keyword arguments passed to the constructor
        of an event are passed on to the handler. When declaring a
        handler, its argument list must therefore match the arguments
        used for creating the event.

        Every event has a :attr:`name` attribute that is used for matching
        the event with the handlers.

        :var success: if this optional attribute is set to
            ``True``, an associated event ``success`` (original name
            with "_success" appended) will automatically be fired when all
            handlers for the event have been invoked successfully.

        :var success_channels: the success event is, by default, delivered
            to same channels as the successfully dispatched event itself.
            This may be overridden by specifying an alternative list of
            destinations using this attribute.

        :var complete: if this optional attribute is set to
            ``True``, an associated event ``complete`` (original name
            with "_complete" appended) will automatically be fired when all
            handlers for the event and all events fired by these handlers
            (recursively) have been invoked successfully.

        :var complete_channels: the complete event is, by default, delivered
            to same channels as the initially dispatched event itself.
            This may be overridden by specifying an alternative list of
            destinations using this attribute.
        """

        self.args = list(args)
        self.kwargs = kwargs

        self.uid = None
        self.handler = None
        self.stopped = False
        self.cancelled = False
        if not hasattr(self, 'name'):
            self.name = self.__class__.__name__

    def __getstate__(self):
        odict = self.__dict__.copy()
        del odict["handler"]
        return odict

    def __setstate__(self, dict):
        self.__dict__.update(dict)

    def __le__(self, other):
        return False

    def __gt__(self, other):
        return False

    def __repr__(self):
        "x.__repr__() <==> repr(x)"

        data = "%s %s" % (
            ", ".join(repr(arg) for arg in self.args),
            ", ".join("%s=%s" % (k, repr(v)) for k, v in self.kwargs.items())
        )

        return "<%s (%s)>" % (self.name, data)

    def __getitem__(self, x):
        """x.__getitem__(y) <==> x[y]

        Get and return data from the event object requested by "x".
        If an int is passed to x, the requested argument from self.args
        is returned index by x. If a str is passed to x, the requested
        keyword argument from self.kwargs is returned keyed by x.
        Otherwise a TypeError is raised as nothing else is valid.
        """

        if isinstance(x, int):
            return self.args[x]
        elif isinstance(x, str):
            return self.kwargs[x]
        else:
            raise TypeError("Expected int or str, got %r" % type(x))

    def __setitem__(self, i, y):
        """x.__setitem__(i, y) <==> x[i] = y

        Modify the data in the event object requested by "x".
        If i is an int, the ith requested argument from self.args
        shall be changed to y. If i is a str, the requested value
        keyed by i from self.kwargs, shall by changed to y.
        Otherwise a TypeError is raised as nothing else is valid.
        """

        if isinstance(i, int):
            self.args[i] = y
        elif isinstance(i, str):
            self.kwargs[i] = y
        else:
            raise TypeError("Expected int or str, got %r" % type(i))

    def cancel(self):
        """Cancel the event from being processed (if not already)"""

        self.cancelled = True

    def stop(self):
        """Stop further processing of this event"""

        self.stopped = True


class started(Event):

    """started Event

    This Event is sent when a Component or Manager has started running.

    :param manager: The component or manager that was started
    :type  manager: Component or Manager
    """

    def __init__(self, manager):
        super(started, self).__init__(manager)


class stopped(Event):

    """stopped Event

    This Event is sent when a Component or Manager has stopped running.

    :param manager: The component or manager that has stopped
    :type  manager: Component or Manager
    """

    def __init__(self, manager):
        super(stopped, self).__init__(manager)


class registered(Event):

    """registered Event

    This Event is sent when a Component has registered with another Component
    or Manager. This Event is only sent if the Component or Manager being
    registered which is not itself.

    :param component: The Component being registered
    :type  component: Component

    :param manager: The Component or Manager being registered with
    :type  manager: Component or Manager
    """

    def __init__(self, component, manager):
        super(registered, self).__init__(component, manager)


class unregistered(Event):

    """unregistered Event

    This Event is sent when a Component has been unregistered from its
    Component or Manager.
    """

