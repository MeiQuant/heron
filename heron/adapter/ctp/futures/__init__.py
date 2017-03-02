# encoding: UTF-8
"""
CTP期货版本适配器

"""


from heron.adapter import BaseAdapter

from .md_adapter import MdAdapter
from .td_adapter import TdAdapter


# todo 实现配置载入方式
def load_setting(name):

    return {}


class Adapter(BaseAdapter):

    def __init__(self):
        super(Adapter, self).__init__()

        self.mdAdapter = MdAdapter(self)
        self.tdAdapter = TdAdapter(self)

        # 是否要启动循环查询
        self.isQryEnabled = False

    def connect(self, config):
        """
        连接服务器
        :param config:
        :return:
        """
        # todo 配置传入方式
        setting = config or load_setting('CTP')
        try:
            userID = str(setting['userID'])
            password = str(setting['password'])
            brokerID = str(setting['brokerID'])
            tdAddress = str(setting['tdAddress'])
            mdAddress = str(setting['mdAddress'])
            userProductInfo = str(setting['userProductInfo'])
            authCode = str(setting['authCode'])
        except KeyError:
            # todo add error & logger

            return

        # 创建行情交易接口适配器
        self.mdAdapter.connect(userID, password, brokerID, mdAddress)
        self.tdAdapter.connect(userID, password, brokerID, tdAddress, userProductInfo, authCode)

        # 初始化并启动查询
        self.initQuery()


    def subscribe(self, subscribeReq):
        """
        订阅市场行情
        :param subscribeReq:
        :return:
        """

        self.mdAdapter.subscribe(subscribeReq)

    def sendOrder(self, orderReq):
        """
        发送订单
        :param orderReq:
        :return:
        """

        return self.tdAdapter.sendOrder(orderReq)

    def cancelOrder(self, cancelOrderReq):
        """
        撤销订单
        :param cancelOrderReq:
        :return:
        """
        self.tdAdapter.cancelOrder(cancelOrderReq)

    def qryAccount(self):
        """
        查询账户资金
        :return:
        """
        self.tdAdapter.qryAccount()

    def qryPosition(self):
        """
        查询持仓
        :return:
        """
        self.tdAdapter.qryPosition()

    def close(self):
        """
        关闭接口
        :return:
        """
        if self.mdAdapter.isConnected:
            self.mdAdapter.close()
        if self.tdAdapter.isConnected:
            self.tdAdapter.close()

        # todo add logger

    def initQuery(self):
        """
        初始化连续查询
        :return:
        """
        if self.isQryEnabled:
            # todo add repeated query

            self.qryCount = 0

    def startQuery(self):
        """
        连续查询启动
        :return:
        """
        pass

    def query(self):
        """
        触发连续查询事件
        :return:
        """
        pass

    def setQryEnabled(self, isQryEnabled):
        """
        设置是否启动连续查询
        :param isQryEnabled:
        :return:
        """
        self.isQryEnabled = isQryEnabled
