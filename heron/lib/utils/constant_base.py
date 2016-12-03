# encoding: UTF-8

"""
常量基类

由于python原生并不支持常量定义,这里增加了常量的约束条件.声明常量时,只需要继承该类,并将常量显性的声明到模块即可

"""


class ConstantBase(object):
    """常量限制类"""

    class ConstError(TypeError):
        def __init__(self):
            pass
        pass

    class ConstCaseError(ConstError):
        def __init__(self):
            pass
        pass

    def __init__(self):
        pass

    def __setattr__(self, key, value):
        if self.__dict__.has_key(key):
            raise self.ConstError, "Can't change const. %s" % key
        if not key.isupper():
            raise self.ConstCaseError, "const name %s is not all uppercase" % key
        self.__dict__[key] = value

