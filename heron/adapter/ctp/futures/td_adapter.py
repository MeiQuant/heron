# encoding: UTF-8
"""
CTP交易API
继承原生API，以实现原生功能
已成BaseAdapter，以获取事件触发能力
"""

import os

from heron.api.ctp.futures.TdApi import TdApi
from heron.adapter import BaseAdapter


class TdAdapter(TdApi, BaseAdapter):

    def __init__(self):
        super(TdAdapter, self).__init()

        self.reqID = 0
        self.orderRef = 0

        self.isConnected = False
        self.isAuth = False
        self.isLogin = False

        self.userID = ''
        self.password = ''
        self.brokerID = ''
        self.address = ''
        # 用户端产品信息
        self.userProductInfo = ''
        # 用户端认证码
        self.authCode = ''

        self.frontID = 0
        self.sessionID = 0

        self.posBufferDict = {}
        self.symbolExchangeDict = {}
        self.symbolSizeDict = {}

    def onFrontConnected(self):
        """
        前置服务器连接成功回调
        :return:
        """

        # todo logger

        # 服务器连接之后进行身份认证

        if not self.isAuth:
            self.auth()

        elif not self.isLogin:
            self.login()

    def onFrontDisconnected(self, n):
        """
        服务器断开回调
        :param n:
        :return:
        """

        # todo logger
        self.isConnected = False
        self.isLogin = False

    def onHeartBeatWarning(self, n):
        pass

    def onRspAuthenticate(self, data, error, n, last):
        """
        身份认证响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """

        if error['ErrorID'] == 0:
            self.isAuth = True

            # todo add logger

            # 执行用户登录
            self.login()

        else:
            # todo add error
            pass

    def onRspUserLogin(self, data, error, n, last):
        """
        登录响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """

        if error['ErrorID'] == 0:
            self.frontID = str(data['FrontID'])
            self.sessionID = str(data['SessionID'])
            self.isLogin = True

            # todo add logger

            req = {
                'BrokerID': self.brokerID,
                'InvestorID': self.userID
            }
            self.reqID += 1
            self.reqSettlementInfoConfirm(req, self.reqID)

        else:
            # todo add error
            pass

    def onRspUserLogout(self, data, error, n, last):
        """
        退出响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        if error['ErrorID'] == 0:
            self.isLogin = False

            # todo add logger
        else:
            # todo add error
            pass

    def onRspUserPasswordUpdate(self, data, error, n, last):
        """
        修改密码响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspTradingAccountPasswordUpdate(self, data, error, n, last):
        """
        交易密码修改响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspOrderInsert(self, data, error, n, last):
        """
        发单错误响应(柜台)
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # todo add error
        pass

    def onRspParkedOrderInsert(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspParkedOrderAction(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspOrderAction(self, data, error, n, last):
        """
        撤单错误
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # todo add error
        pass

    def onRspQueryMaxOrderVolume(self, data, error, n, last):
        """
        查询单笔最大交易量响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # todo 查询最大交易量
        pass

    def onRspSettlementInfoConfirm(self, data, error, n, last):
        """
        确认结算信息响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # todo add logger & 实现结算单查询

        # 查询合约代码
        self.reqID += 1
        self.reqQryInstrument({}, self.reqID)

    def onRspRemoveParkedOrder(self, data, error, n, last):
        """
        删除预埋单响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspRemoveParkedOrderAction(self, data, error, n, last):
        """
        删除预埋撤单响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspExecOrderInsert(self, data, error, n, last):
        """
        执行宣告录入请求响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspExecOrderAction(self, data, error, n, last):
        """
        执行宣告操作请求响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspForQuoteInsert(self, data, error, n, last):
        """
        询价录入请求响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQuoteInsert(self, data, error, n, last):
        """
        报价录入请求响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQuoteAction(self, data, error, n, last):
        """
        报价操作请求响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspLockInsert(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspCombActionInsert(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryOrder(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryTrade(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInvestorPostion(self, data, error, n, last):
        """
        仓位查询响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        positionName = '.'.join([data['InstrumentID'], data['PosiDirection']])

        if positionName in self.posBufferDict:
            posBuffer = self.posBufferDict[positionName]
        else:
            # todo 重构仓位信息缓存
            # posBuffer = PositionBuffer(data, 'ctp')

        # 更新持仓缓存
        pass


    def onRspQryTradingAccount(self, data, error, n, last):
        """
        资金账户查询
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # todo 实现资金账户查询
        pass

    def onRspQryInvestor(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryTradingCode(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInstrumentMarginRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInstrumentCommissionRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExchange(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryProduct(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInstrument(self, data, error, n, last):
        """
        合约信息查询响应
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """

        # todo 实现合约信息查询

        pass

    def onRspQryDepthMarketData(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQrySettlementInfo(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryTransferBank(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInvestorPositionDetail(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryNotice(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQrySettlementInfoConfirm(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInvestorPositionCombineDetail(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryCFMMCTradingAccountKey(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryEWarrantOffset(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInvestorProductGroupMargin(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExchangeMarginRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExchangeMarginRateAdjust(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExchangeRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQrySecAgentACIDMap(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryProductExchRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryProductGroup(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryOptionInstrTradeCost(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryOptionInstrCommRate(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExecOrder(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryForQuote(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryQuote(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryLock(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryLockPosition(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryInvestorLevel(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryExecFreeze(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryCombInstrumentGuard(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryCombAction(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryTransferSerial(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryAccountregister(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspError(self, error, n, last):
        """
        错误信息响应
        :param error:
        :param n:
        :param last:
        :return:
        """

        # todo add error

        pass

    def onRtnOrder(self, data):
        """
        发单响应
        :param data:
        :return:
        """
        # 更新最大报单编号
        newref = data['OrderRef']
        self.orderRef = max(self.orderRef, int(newref))

        # 实现发单响应

        pass

    def onRtnTrade(self, data):
        """
        成交响应
        :param data:
        :return:
        """
        # 创建报单数据对象

        # todo 实现成交

        pass

    def onErrRtnOrderInsert(self, data, error):
        """
        发单错误响应（交易所）
        :param data:
        :param error:
        :return:
        """

       # todo add error

        pass

    def onErrRtnOrderAction(self, data, error):
        """
        撤单错误响应（交易所）
        :param data:
        :param error:
        :return:
        """

        # todo add error

        pass

    def onRtnInstrumentStatus(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnTradingNotice(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnErrorConditionalOrder(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnExecOrder(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onErrRtnExecOrderInsert(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnExecOrderAction(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnForQuoteInsert(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onRtnQuote(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onErrRtnQuoteInsert(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnQuoteAction(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onRtnForQuoteRsp(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnCFMMCTradingAccountToken(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnLock(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onErrRtnLockInsert(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onRtnCombAction(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onErrRtnCombActionInsert(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onRspQryContractBank(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryParkedOrder(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryParkedOrderAction(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryTradingNotice(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryBrokerTradingParams(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQryBrokerTradingAlgos(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQueryCFMMCTradingAccountToken(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRtnFromBankToFutureByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnFromFutureToBankByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnRepealFromBankToFutureByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnRepealFromFutureToBankByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnFromBankToFutureByFuture(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnFromFutureToBankByFuture(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnRepealFromBankToFutureByFutureManual(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnRepealFromFutureToBankByFutureManual(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnQueryBankBalanceByFuture(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onErrRtnBankToFutureByFuture(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnFutureToBankByFuture(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnRepealBankToFutureByFutureManual(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnRepealFutureToBankByFutureManual(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onErrRtnQueryBankBalanceByFuture(self, data, error):
        """

        :param data:
        :param error:
        :return:
        """
        pass

    def onRtnRepealFromBankToFutureByFuture(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnRepealFromFutureToBankByFuture(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRspFromBankToFutureByFuture(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspFromFutureToBankByFuture(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspQueryBankAccountMoneyByFuture(self, data, error, n, last):
        """

        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRtnOpenAccountByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnCancelAccountByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def onRtnChangeAccountByBank(self, data):
        """

        :param data:
        :return:
        """
        pass

    def connect(self, userID, password, brokerID, address, userproductinfo='', autocode=''):
        """
        初始化连接
        :param userID:
        :param password:
        :param brokerID:
        :param address:
        :param userproductinfo:
        :param autocode:
        :return:
        """
        self.userID = userID  # 账号
        self.password = password  # 密码
        self.brokerID = brokerID  # 经纪商代码
        self.address = address  # 服务器地址

        if userproductinfo and autocode:
            self.userProductInfo = userproductinfo
            self.authCode = autocode
            self.isAuth = False

        # 如果尚未建立服务器连接，则进行连接
        if not self.connectionStatus:
            # 创建C++环境中的API对象，这里传入的参数是需要用来保存.con文件的文件夹路径
            path = os.getcwd() + '/var/temp/ctp/futures/'
            if not os.path.exists(path):
                os.makedirs(path)
            self.createFtdcTraderApi(path)

            # 设置数据同步模式为推送从今日开始所有数据
            self.subscribePrivateTopic(0)
            self.subscribePublicTopic(0)

            # 注册服务器地址
            self.registerFront(self.address)

            # 初始化连接，成功会调用onFrontConnected
            self.init()

        # 若已经连接但尚未登录，则进行登录
        else:
            if not self.isAuth:
                self.auth()

            elif not self.isLogin:
                self.login()

    def login(self):
        """
        执行用户登录
        :return:
        """
        # 如果填入了用户名密码等，则登录
        if self.userID and self.password and self.brokerID:
            req = {
                'UserID': self.userID,
                'Password': self.password,
                'BrokerID': self.brokerID
            }
            self.reqID += 1
            self.reqUserLogin(req, self.reqID)

    def auth(self):
        """
        进行用户端身份认证
        :return:
        """
        if self.authCode and self.userProductInfo:
            req = {
                'AuthCode': self.authCode,
                'UserProductInfo': self.userProductInfo,
                'BrokerID': self.brokerID,
                'UserID': self.userID
            }
            self.reqID += 1
            self.reqAuthenticate(req, self.reqID)

    def qryAccount(self):
        """查询账户"""
        self.reqID += 1
        self.reqQryTradingAccount({}, self.reqID)

    def qryPosition(self):
        """查询持仓"""
        self.reqID += 1
        req = {
            'BrokerID': self.brokerID,
            'InvestorID': self.userID
        }
        self.reqQryInvestorPosition(req, self.reqID)

    def sendOrder(self, orderReq):
        """
        发单
        :param orderReq:
        :return:
        """
        self.reqID += 1
        self.orderRef += 1

        # todo 实现发单

        pass

    def cancelOrder(self, cancelOrderReq):
        """撤单"""
        self.reqID += 1

        req = {}

        req['InstrumentID'] = cancelOrderReq.symbol
        req['ExchangeID'] = cancelOrderReq.exchange
        req['OrderRef'] = cancelOrderReq.orderID
        req['FrontID'] = cancelOrderReq.frontID
        req['SessionID'] = cancelOrderReq.sessionID

        req['ActionFlag'] = defineDict['THOST_FTDC_AF_Delete']
        req['BrokerID'] = self.brokerID
        req['InvestorID'] = self.userID

        self.reqOrderAction(req, self.reqID)
        print req

    def logout(self):
        """用户退出"""
        if self.userID and self.brokerID:
            req = {}
            req['UserID'] = self.userID
            req['BrokerID'] = self.brokerID
            self.reqID += 1
            self.reqUserLogout(req, self.reqID)

    def close(self):
        """关闭"""
        self.exit()