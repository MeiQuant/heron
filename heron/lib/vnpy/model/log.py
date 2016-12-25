# encoding: UTF-8
"""
日志
"""


from heron.lib.vnpy.constant import EMPTY_UNICODE
from heron.lib.utils.date import now



from base import Base


class Log(Base):

     def __init__(self):
        """Constructor"""
        super(Log, self).__init__()

        self.time = now()    # 日志生成时间
        self.content = EMPTY_UNICODE                         # 日志信息