# encoding: UTF-8
"""
仓位缓存
"""

from copy import copy

from heron.lib.vnpy.constant import EMPTY_INT, EMPTY_FLOAT
from heron.lib.vnpy.data import Position

class PositionBuffer(object):
    """用来缓存持仓的数据，处理上期所的数据返回分今昨的问题"""

    # ----------------------------------------------------------------------
    def __init__(self, data, gatewayName):
        """Constructor"""
        self.symbol = data['InstrumentID']
        self.direction = posiDirectionMapReverse.get(data['PosiDirection'], '')

        self.todayPosition = EMPTY_INT
        self.ydPosition = EMPTY_INT
        self.todayPositionCost = EMPTY_FLOAT
        self.ydPositionCost = EMPTY_FLOAT

        # 通过提前创建持仓数据对象并重复使用的方式来降低开销
        pos = Position()
        pos.symbol = self.symbol
        pos.vtSymbol = self.symbol
        pos.gatewayName = gatewayName
        pos.direction = self.direction
        pos.vtPositionName = '.'.join([pos.vtSymbol, pos.direction])
        self.pos = pos

    # ----------------------------------------------------------------------
    def updateShfeBuffer(self, data, size):
        """更新上期所缓存，返回更新后的持仓数据"""
        # 昨仓和今仓的数据更新是分在两条记录里的，因此需要判断检查该条记录对应仓位
        # 因为今仓字段TodayPosition可能变为0（被全部平仓），因此分辨今昨仓需要用YdPosition字段
        if data['YdPosition']:
            self.ydPosition = data['Position']
            self.ydPositionCost = data['PositionCost']
        else:
            self.todayPosition = data['Position']
            self.todayPositionCost = data['PositionCost']

            # 持仓的昨仓和今仓相加后为总持仓
        self.pos.position = self.todayPosition + self.ydPosition
        self.pos.ydPosition = self.ydPosition

        # 如果手头还有持仓，则通过加权平均方式计算持仓均价
        if self.todayPosition or self.ydPosition:
            self.pos.price = ((self.todayPositionCost + self.ydPositionCost) /
                              ((self.todayPosition + self.ydPosition) * size))
        # 否则价格为0
        else:
            self.pos.price = 0

        return copy(self.pos)

    # ----------------------------------------------------------------------
    def updateBuffer(self, data, size):
        """更新其他交易所的缓存，返回更新后的持仓数据"""
        # 其他交易所并不区分今昨，因此只关心总仓位，昨仓设为0
        self.pos.position = data['Position']
        self.pos.ydPosition = 0

        if data['Position']:
            self.pos.price = data['PositionCost'] / (data['Position'] * size)
        else:
            self.pos.price = 0

        return copy(self.pos)

        # ----------------------------------------------------------------------

    def getPos(self):
        """获取当前的持仓数据"""
        return copy(self.pos)