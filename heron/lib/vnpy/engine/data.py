# encoding: UTF-8
"""
数据引擎
"""

import shelve

from heron.lib.vnpy.event.type import EVENT_CONTRACT, EVENT_ORDER
from heron.lib.vnpy.constant import STATUS_CANCELLED, STATUS_ALLTRADED


class DataEngine(object):
    """数据引擎"""
    contractFileName = 'var/ContractData.vt'

    def __init__(self, eventEngine):
        """Constructor"""
        self.eventEngine = eventEngine

        # 保存合约详细信息的字典
        self.contractDict = {}

        # 保存委托数据的字典
        self.orderDict = {}

        # 保存活动委托数据的字典（即可撤销）
        self.workingOrderDict = {}

        # 读取保存在硬盘的合约数据
        self.loadContracts()

        # 注册事件监听
        self.registerEvent()

    def updateContract(self, event):
        """更新合约数据"""
        contract = event.dict_['data']
        self.contractDict[contract.vtSymbol] = contract
        self.contractDict[contract.symbol] = contract  # 使用常规代码（不包括交易所）可能导致重复

    def getContract(self, vtSymbol):
        """查询合约对象"""
        try:
            return self.contractDict[vtSymbol]
        except KeyError:
            return None

    def getAllContracts(self):
        """查询所有合约对象（返回列表）"""
        return self.contractDict.values()

    def saveContracts(self):
        """保存所有合约对象到硬盘"""
        f = shelve.open(self.contractFileName)
        f['data'] = self.contractDict
        f.close()

    def loadContracts(self):
        """从硬盘读取合约对象"""
        f = shelve.open(self.contractFileName)
        if 'data' in f:
            d = f['data']
            for key, value in d.items():
                self.contractDict[key] = value
        f.close()

    def updateOrder(self, event):
        """更新委托数据"""
        order = event.dict_['data']
        self.orderDict[order.vtOrderID] = order

        # 如果订单的状态是全部成交或者撤销，则需要从workingOrderDict中移除
        if order.status == STATUS_ALLTRADED or order.status == STATUS_CANCELLED:
            if order.vtOrderID in self.workingOrderDict:
                del self.workingOrderDict[order.vtOrderID]
        # 否则则更新字典中的数据
        else:
            self.workingOrderDict[order.vtOrderID] = order

    def getOrder(self, vtOrderID):
        """查询委托"""
        try:
            return self.orderDict[vtOrderID]
        except KeyError:
            return None

    def getAllWorkingOrders(self):
        """查询所有活动委托（返回列表）"""
        return self.workingOrderDict.values()

    def registerEvent(self):
        """注册事件监听"""
        self.eventEngine.register(EVENT_CONTRACT, self.updateContract)
        self.eventEngine.register(EVENT_ORDER, self.updateOrder)
