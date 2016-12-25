# encoding: UTF-8
"""
合约信息
"""

from heron.lib.vnpy.constant import EMPTY_UNICODE, EMPTY_STRING, EMPTY_FLOAT, EMPTY_INT

from base import Base


class Contract(Base):
    """合约详细信息类"""

    def __init__(self):
        """Constructor"""
        super(Contract, self).__init__()

        self.symbol = EMPTY_STRING              # 代码
        self.exchange = EMPTY_STRING            # 交易所代码
        self.vtSymbol = EMPTY_STRING            # 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码
        self.name = EMPTY_UNICODE               # 合约中文名

        self.productClass = EMPTY_UNICODE       # 合约类型
        self.size = EMPTY_INT                   # 合约大小
        self.priceTick = EMPTY_FLOAT            # 合约最小价格TICK

        # 期权相关
        self.strikePrice = EMPTY_FLOAT          # 期权行权价
        self.underlyingSymbol = EMPTY_STRING    # 标的物合约代码
        self.optionType = EMPTY_UNICODE         # 期权类型
