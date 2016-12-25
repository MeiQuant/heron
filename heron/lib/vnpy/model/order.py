# encoding: UTF-8
"""
订单数据
"""
from heron.lib.vnpy.constant import EMPTY_UNICODE, EMPTY_FLOAT, EMPTY_STRING, EMPTY_INT

from base import Base


class Order(Base):
    def __init__(self):
        """Constructor"""
        super(Order, self).__init__()

        # 代码编号相关
        self.symbol = EMPTY_STRING              # 合约代码
        self.exchange = EMPTY_STRING            # 交易所代码
        self.vtSymbol = EMPTY_STRING            # 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

        self.orderID = EMPTY_STRING             # 订单编号
        self.vtOrderID = EMPTY_STRING           # 订单在vt系统中的唯一编号，通常是 Gateway名.订单编号

        # 报单相关
        self.direction = EMPTY_UNICODE          # 报单方向
        self.offset = EMPTY_UNICODE             # 报单开平仓
        self.price = EMPTY_FLOAT                # 报单价格
        self.totalVolume = EMPTY_INT            # 报单总数量
        self.tradedVolume = EMPTY_INT           # 报单成交数量
        self.status = EMPTY_UNICODE             # 报单状态

        self.orderTime = EMPTY_STRING           # 发单时间
        self.cancelTime = EMPTY_STRING          # 撤单时间

        # CTP/LTS相关
        self.frontID = EMPTY_INT                # 前置机编号
        self.sessionID = EMPTY_INT              # 连接编号
