# encoding: UTF-8
"""
This module define the @handler decorator/function and the HandlesType type.
"""
from collections import Callable
from inspect import getargspec


def handler(*names, **kwargs):
    """Creates an Event Handler

    This decorator can be applied to methods of classes derived from
    :class:`circuits.core.components.BaseComponent`. It marks the method as a
    handler for the events passed as arguments to the ``@handler`` decorator.
    The events are specified by their name.

    The decorated method's arguments must match the arguments passed to the
    :class:`circuits.core.events.Event` on creation. Optionally, the
    method may have an additional first argument named *event*. If declared,
    the event object that caused the handler to be invoked is assigned to it.

    Keyword argument ``priority`` influences the order in which handlers
    for a specific event are invoked. The higher the priority, the earlier
    the handler is executed.

    If you want to override a handler defined in a base class of your
    component, you must specify ``override=True``, else your method becomes
    an additional handler for the event.

    **Return value**
    The results returned by the handlers for an event are simply
    collected in the :class:`heron.core.events.Event`'s :attr:`value`
    attribute.
    """

    def wrapper(f):
        if names and isinstance(names[0], bool) and not names[0]:
            f.handler = False
            return f

        f.handler = True

        f.names = names
        f.priority = kwargs.get("priority", 0)
        f.override = kwargs.get("override", False)

        args = getargspec(f)[0]

        if args and args[0] == "self":
            del args[0]
        f.event = getattr(f, "event", bool(args and args[0] == "event"))

        return f

    return wrapper


class Unknown(object):

    """Unknown Dummy Component"""


def reprhandler(handler):
    format = "<handler[%s][%s]%s (%s.%s)>"

    names = ",".join(handler.names)

    instance = getattr(
        handler, "im_self", getattr(
            handler, "__self__", Unknown()
        )
    ).__class__.__name__

    method = handler.__name__

    priority = "[%0.2f]" % (handler.priority,) if handler.priority else ""

    return format % (names, priority, instance, method)


class HandlerMetaClass(type):

    def __init__(cls, name, bases, ns):
        super(HandlerMetaClass, cls).__init__(name, bases, ns)

        callables = (x for x in ns.items() if isinstance(x[1], Callable))
        for name, callable in callables:
            if not (name.startswith("_") or hasattr(callable, "handler")):
                setattr(cls, name, handler(name)(callable))
