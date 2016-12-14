# encoding: UTF-8
"""
CTP接口实现
"""

from heron.lib.vnpy.data import Log
from heron.lib.vnpy.gateway import GatewayBase
from heron.lib.vnpy.event.type import EVENT_TIMER
from heron.lib.vnpy.settings import load_setting

from ctp_md_api import CtpMdApi
from ctp_td_api import CtpTdApi


class CtpGateway(GatewayBase):
    """CTP接口"""

    # ----------------------------------------------------------------------
    def __init__(self, eventEngine, gatewayName='CTP'):
        """Constructor"""
        super(CtpGateway, self).__init__(eventEngine, gatewayName)

        self.mdApi = CtpMdApi(self)  # 行情API
        self.tdApi = CtpTdApi(self)  # 交易API

        self.mdConnected = False  # 行情API连接状态，登录完成后为True
        self.tdConnected = False  # 交易API连接状态

        self.qryEnabled = False  # 是否要启动循环查询

    # ----------------------------------------------------------------------
    def connect(self):
        """连接"""
        # 读取配置, todo 服务器地址由客户端传入
        setting = load_setting('CTP')
        try:
            userID = str(setting['userID'])
            password = str(setting['password'])
            brokerID = str(setting['brokerID'])
            tdAddress = str(setting['tdAddress'])
            mdAddress = str(setting['mdAddress'])
        except KeyError:
            log = Log()
            log.gatewayName = self.gatewayName
            log.content = u'连接配置缺少字段，请检查'
            self.onLog(log)
            return

            # 创建行情和交易接口对象
        self.mdApi.connect(userID, password, brokerID, mdAddress)
        self.tdApi.connect(userID, password, brokerID, tdAddress)

        # 初始化并启动查询
        self.initQuery()

    # ----------------------------------------------------------------------
    def subscribe(self, subscribeReq):
        """订阅行情"""
        self.mdApi.subscribe(subscribeReq)

    # ----------------------------------------------------------------------
    def sendOrder(self, orderReq):
        """发单"""
        return self.tdApi.sendOrder(orderReq)

    # ----------------------------------------------------------------------
    def cancelOrder(self, cancelOrderReq):
        """撤单"""
        self.tdApi.cancelOrder(cancelOrderReq)

    # ----------------------------------------------------------------------
    def qryAccount(self):
        """查询账户资金"""
        self.tdApi.qryAccount()

    # ----------------------------------------------------------------------
    def qryPosition(self):
        """查询持仓"""
        self.tdApi.qryPosition()

    # ----------------------------------------------------------------------
    def close(self):
        """关闭"""
        if self.mdConnected:
            self.mdApi.close()
        if self.tdConnected:
            self.tdApi.close()

        # todo 确认断开之后再生成log
        log = Log()
        log.gatewayName = self.gatewayName
        log.content = u'已断开与柜台的通信'
        self.onLog(log)

    # ----------------------------------------------------------------------
    def initQuery(self):
        """初始化连续查询"""
        if self.qryEnabled:
            # 需要循环的查询函数列表
            self.qryFunctionList = [self.qryAccount, self.qryPosition]

            self.qryCount = 0  # 查询触发倒计时
            self.qryTrigger = 2  # 查询触发点
            self.qryNextFunction = 0  # 上次运行的查询函数索引

            self.startQuery()

    # ----------------------------------------------------------------------
    def query(self, event):
        """注册到事件处理引擎上的查询函数"""
        self.qryCount += 1

        if self.qryCount > self.qryTrigger:
            # 清空倒计时
            self.qryCount = 0

            # 执行查询函数
            function = self.qryFunctionList[self.qryNextFunction]
            function()

            # 计算下次查询函数的索引，如果超过了列表长度，则重新设为0
            self.qryNextFunction += 1
            if self.qryNextFunction == len(self.qryFunctionList):
                self.qryNextFunction = 0

    # ----------------------------------------------------------------------
    def startQuery(self):
        """启动连续查询"""
        self.eventEngine.register(EVENT_TIMER, self.query)

    # ----------------------------------------------------------------------
    def setQryEnabled(self, qryEnabled):
        """设置是否要启动循环查询"""
        self.qryEnabled = qryEnabled

