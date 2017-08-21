# encoding: UTF-8
"""
This module defines the basic event class and common events.

"""


# todo refactor event class
class Event(object):

    def __init__(self, *args, **kwargs):
        """
        An event is a message send to components architecture.
        It is eventually dispatched to all components that have handlers
        for one of the event type.

        All normal arguments and keyword arguments passed to the constructor
        of an event are passed on to the handler. When declaring a
        handler, its argument list must therefore match the arguments
        used for creating the event.

        Every event has a :attr:`name` attribute that is used for matching
        the event with the handlers.
        """

        self.args = list(args)
        self.kwargs = kwargs

        if not hasattr(self, 'name'):
            self.name = self.__class__.__name__

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