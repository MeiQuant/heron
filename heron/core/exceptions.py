# encoding: UTF-8
"""
Error定义
"""


class HeronException(Exception):
    """
    Heron Base Exception
    """
    pass


class HeronError(HeronException):
    """
    Heron Base Error
    """
    pass


class HeronSettingsError(HeronError):
    """
    Heron Settings Error
    """

    def __init__(self):
        pass

    pass


class HeronConstantError(TypeError):
    def __init__(self):
        pass

    pass



class HeronWarning(Exception):
    """
    Heron Base Excepotion
    """
    pass

