# encoding: UTF-8
"""
K线数据
"""

from heron.lib.vnpy.constant import EMPTY_FLOAT, EMPTY_INT, EMPTY_STRING

class Bar(object):
    def __init__(self):
        """Constructor"""
        self.vtSymbol = EMPTY_STRING  # vt系统代码
        self.symbol = EMPTY_STRING  # 代码
        self.exchange = EMPTY_STRING  # 交易所

        self.open = EMPTY_FLOAT  # OHLC
        self.high = EMPTY_FLOAT
        self.low = EMPTY_FLOAT
        self.close = EMPTY_FLOAT

        self.date = EMPTY_STRING  # bar开始的时间，日期
        self.time = EMPTY_STRING  # 时间
        self.datetime = None  # python的datetime时间对象

        self.volume = EMPTY_INT  # 成交量
        self.openInterest = EMPTY_INT  # 持仓量