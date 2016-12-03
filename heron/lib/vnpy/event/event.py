# encoding: UTF-8
"""
事件类
"""


class Event:
    def __init__(self, type_=None):
        """Constructor"""
        self.type_ = type_      # 事件类型
        self.dict_ = {}         # 字典用于保存具体的事件数据