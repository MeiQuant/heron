# encoding: UTF-8
"""
订阅行情请求类
"""

from heron.lib.vnpy.constant import EMPTY_STRING, EMPTY_UNICODE, EMPTY_FLOAT


class SubscribeReq(object):
    """订阅行情时传入的对象类"""


    def __init__(self):
        """Constructor"""
        self.symbol = EMPTY_STRING              # 代码
        self.exchange = EMPTY_STRING            # 交易所

        # 以下为IB相关
        self.productClass = EMPTY_UNICODE       # 合约类型
        self.currency = EMPTY_STRING            # 合约货币
        self.expiry = EMPTY_STRING              # 到期日
        self.strikePrice = EMPTY_FLOAT          # 行权价
        self.optionType = EMPTY_UNICODE         # 期权类型