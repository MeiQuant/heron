# encoding: UTF-8
"""
日志
"""

import time

from heron.lib.vnpy.constant import EMPTY_UNICODE

from base import Base


class Log(Base):

     def __init__(self):
        """Constructor"""
        super(Log, self).__init__()

        self.logTime = time.strftime('%X', time.localtime())    # 日志生成时间
        self.logContent = EMPTY_UNICODE                         # 日志信息