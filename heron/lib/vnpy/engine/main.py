# encoding: UTF-8
"""
主引擎
vnpy交易系统的主入口
"""

from collections import OrderedDict

from pymongo import MongoClient
from pymongo.errors import ConnectionFailure

from heron.lib.vnpy.gateway.ctp import CtpGateway
from heron.lib.vnpy.event import EventEngine, Event
from heron.lib.vnpy.event.type import EVENT_LOG
from heron.lib.vnpy.data import Log
from heron.lib.vnpy.settings import load_setting

from data import DataEngine
from data_record import DataRecordEngine
from risk import RiskManagerEngine


class MainEngine(object):
    """主引擎"""

    # ----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        # 创建事件引擎
        self.eventEngine = EventEngine()
        self.eventEngine.start()

        # 创建数据引擎
        self.dataEngine = DataEngine(self.eventEngine)

        # MongoDB数据库相关
        self.dbClient = None  # MongoDB客户端对象

        # 用来保存接口对象的字典
        self.gatewayDict = OrderedDict()

        # 调用一个个初始化函数
        self.initGateway()

        # todo 扩展模块
        # self.ctaEngine = CtaEngine(self, self.eventEngine)
        self.drEngine = DataRecordEngine(self, self.eventEngine)
        self.rmEngine = RiskManagerEngine(self, self.eventEngine)

    # ----------------------------------------------------------------------
    def initGateway(self):
        """初始化接口对象"""

        # 创建我们想要接入的接口对象
        try:
            self.addGateway(CtpGateway, 'CTP')
            self.gatewayDict['CTP'].setQryEnabled(True)
        except Exception, e:
            print e

    # ----------------------------------------------------------------------

    def addGateway(self, gateway, gatewayName=None):
        """创建接口"""
        self.gatewayDict[gatewayName] = gateway(self.eventEngine, gatewayName)

    # ----------------------------------------------------------------------
    def connect(self, gatewayName):
        """连接特定名称的接口"""
        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            gateway.connect()
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

    # ----------------------------------------------------------------------
    def subscribe(self, subscribeReq, gatewayName):
        """订阅特定接口的行情"""
        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            gateway.subscribe(subscribeReq)
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

            # ----------------------------------------------------------------------

    def sendOrder(self, orderReq, gatewayName):
        """对特定接口发单"""
        # 如果风控检查失败则不发单
        if not self.rmEngine.checkRisk(orderReq):
            return ''

        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            return gateway.sendOrder(orderReq)
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

            # ----------------------------------------------------------------------

    def cancelOrder(self, cancelOrderReq, gatewayName):
        """对特定接口撤单"""
        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            gateway.cancelOrder(cancelOrderReq)
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

            # ----------------------------------------------------------------------

    def qryAccount(self, gatewayName):
        """查询特定接口的账户"""
        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            gateway.qryAccount()
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

            # ----------------------------------------------------------------------

    def qryPosition(self, gatewayName):
        """查询特定接口的持仓"""
        if gatewayName in self.gatewayDict:
            gateway = self.gatewayDict[gatewayName]
            gateway.qryPosition()
        else:
            self.writeLog(u'接口不存在：%s' % gatewayName)

            # ----------------------------------------------------------------------

    def exit(self):
        """退出程序前调用，保证正常退出"""
        # 安全关闭所有接口
        for gateway in self.gatewayDict.values():
            gateway.close()

        # 停止事件引擎
        self.eventEngine.stop()

        # 停止数据记录引擎
        self.drEngine.stop()

        # 保存数据引擎里的合约数据到硬盘
        self.dataEngine.saveContracts()

    # ----------------------------------------------------------------------
    def writeLog(self, content):
        """快速发出日志事件"""
        log = Log()
        log.content = content
        event = Event(type_=EVENT_LOG)
        event.dict_['data'] = log
        self.eventEngine.put(event)

        # ----------------------------------------------------------------------

    def dbConnect(self):
        """连接MongoDB数据库"""
        if not self.dbClient:
            # 读取MongoDB的设置

            with load_setting('MongoDB') as mongo_setting:

                host = mongo_setting['host']
                port = mongo_setting['port']

                try:
                    # 设置MongoDB操作的超时时间为0.5秒
                    self.dbClient = MongoClient(host, port, connectTimeoutMS=500)

                    # 调用server_info查询服务器状态，防止服务器异常并未连接成功
                    self.dbClient.server_info()

                    self.writeLog(u'MongoDB连接成功')
                except ConnectionFailure:
                    self.writeLog(u'MongoDB连接失败')

    # ----------------------------------------------------------------------
    def dbInsert(self, dbName, collectionName, d):
        """向MongoDB中插入数据，d是具体数据"""
        if self.dbClient:
            db = self.dbClient[dbName]
            collection = db[collectionName]
            collection.insert_one(d)

    # ----------------------------------------------------------------------
    def dbQuery(self, dbName, collectionName, d):
        """从MongoDB中读取数据，d是查询要求，返回的是数据库查询的指针"""
        if self.dbClient:
            db = self.dbClient[dbName]
            collection = db[collectionName]
            cursor = collection.find(d)
            return cursor
        else:
            return None

    # ----------------------------------------------------------------------
    def dbUpdate(self, dbName, collectionName, d, flt, upsert=False):
        """向MongoDB中更新数据，d是具体数据，flt是过滤条件，upsert代表若无是否要插入"""
        if self.dbClient:
            db = self.dbClient[dbName]
            collection = db[collectionName]
            collection.replace_one(flt, d, upsert)

    # ----------------------------------------------------------------------
    def getContract(self, vtSymbol):
        """查询合约"""
        return self.dataEngine.getContract(vtSymbol)

    # ----------------------------------------------------------------------
    def getAllContracts(self):
        """查询所有合约（返回列表）"""
        return self.dataEngine.getAllContracts()

    # ----------------------------------------------------------------------
    def getOrder(self, vtOrderID):
        """查询委托"""
        return self.dataEngine.getOrder(vtOrderID)

    # ----------------------------------------------------------------------
    def getAllWorkingOrders(self):
        """查询所有的活跃的委托（返回列表）"""
        return self.dataEngine.getAllWorkingOrders()
