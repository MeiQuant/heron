# encoding: UTF-8
"""
错误
"""
import time

from heron.lib.vnpy.constant import EMPTY_STRING, EMPTY_UNICODE

from base import Base


class Error(Base):

    def __init__(self):
        """Constructor"""
        super(Error, self).__init__()

        self.errorID = EMPTY_STRING             # 错误代码
        self.errorMsg = EMPTY_UNICODE           # 错误信息
        self.additionalInfo = EMPTY_UNICODE     # 补充信息

        self.errorTime = time.strftime('%X', time.localtime())    # 错误生成时间