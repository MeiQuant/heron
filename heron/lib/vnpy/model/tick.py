# encoding: UTF-8

"""
Tick行情数据类
"""

from heron.lib.vnpy.constant import EMPTY_FLOAT, EMPTY_STRING, EMPTY_INT

from base import Base


class Tick(Base):
    def __init__(self):
        """Constructor"""
        super(Tick, self).__init__()

        # 代码相关
        self.symbol = EMPTY_STRING              # 合约代码
        self.exchange = EMPTY_STRING            # 交易所代码
        self.vtSymbol = EMPTY_STRING            # 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

        # 成交数据
        self.lastPrice = EMPTY_FLOAT            # 最新成交价
        self.lastVolume = EMPTY_INT             # 最新成交量
        self.volume = EMPTY_INT                 # 今天总成交量
        self.openInterest = EMPTY_INT           # 持仓量
        self.time = EMPTY_STRING                # 时间 11:20:56.5
        self.date = EMPTY_STRING                # 日期 20151009
        self.datetime = None

        # 常规行情
        self.openPrice = EMPTY_FLOAT            # 今日开盘价
        self.highPrice = EMPTY_FLOAT            # 今日最高价
        self.lowPrice = EMPTY_FLOAT             # 今日最低价
        self.preClosePrice = EMPTY_FLOAT

        self.upperLimit = EMPTY_FLOAT           # 涨停价
        self.lowerLimit = EMPTY_FLOAT           # 跌停价

        # 五档行情
        self.bidPrice1 = EMPTY_FLOAT
        self.bidPrice2 = EMPTY_FLOAT
        self.bidPrice3 = EMPTY_FLOAT
        self.bidPrice4 = EMPTY_FLOAT
        self.bidPrice5 = EMPTY_FLOAT

        self.askPrice1 = EMPTY_FLOAT
        self.askPrice2 = EMPTY_FLOAT
        self.askPrice3 = EMPTY_FLOAT
        self.askPrice4 = EMPTY_FLOAT
        self.askPrice5 = EMPTY_FLOAT

        self.bidVolume1 = EMPTY_INT
        self.bidVolume2 = EMPTY_INT
        self.bidVolume3 = EMPTY_INT
        self.bidVolume4 = EMPTY_INT
        self.bidVolume5 = EMPTY_INT

        self.askVolume1 = EMPTY_INT
        self.askVolume2 = EMPTY_INT
        self.askVolume3 = EMPTY_INT
        self.askVolume4 = EMPTY_INT
        self.askVolume5 = EMPTY_INT

