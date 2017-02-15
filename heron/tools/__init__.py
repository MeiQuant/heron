# encoding: UTF-8
"""
公共工具
"""

from warnings import warn


def tryimport(modules, obj=None, message=None):
    modules = (modules,) if isinstance(modules, str) else modules

    for module in modules:
        try:
            m = __import__(module, globals(), locals())
            return getattr(m, obj) if obj is not None else m
        except:
            pass

    if message is not None:
        warn(message)