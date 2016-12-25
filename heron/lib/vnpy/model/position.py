# encoding: UTF-8
"""
仓位数据
"""
from heron.lib.vnpy.constant import EMPTY_INT, EMPTY_STRING, EMPTY_FLOAT

from base import Base


class Position(Base):

    def __init__(self):
        """Constructor"""
        super(Position, self).__init__()

        # 代码编号相关
        self.symbol = EMPTY_STRING              # 合约代码
        self.exchange = EMPTY_STRING            # 交易所代码
        self.vtSymbol = EMPTY_STRING            # 合约在vt系统中的唯一代码，合约代码.交易所代码

        # 持仓相关
        self.direction = EMPTY_STRING           # 持仓方向
        self.position = EMPTY_INT               # 持仓量
        self.frozen = EMPTY_INT                 # 冻结数量
        self.price = EMPTY_FLOAT                # 持仓均价
        self.vtPositionName = EMPTY_STRING      # 持仓在vt系统中的唯一代码，通常是vtSymbol.方向

        # 20151020添加
        self.ydPosition = EMPTY_INT             # 昨持仓