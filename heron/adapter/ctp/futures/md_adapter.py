# encoding: UTF-8
"""
CTP行情API-期货版
继承原生API，以实现原生功能
已成BaseAdapter，以获取事件触发能力
"""

import os

from heron.api.ctp.futures.MdApi import MdApi
from heron.adapter import BaseAdapter


class MdAdapter(MdApi, BaseAdapter):

    def __init__(self):
        super(MdAdapter, self).__init__()

        self.reqID = 0

        self.isConnected = False
        self.isLogin = False

        self.subscribedSymbols = set()

        self.userID = ''
        self.password = ''
        self.brokerID = ''
        self.address = ''

    def onFrontConnected(self):
        """
        前置服务器连接成功回调
        """
        self.connectionStatus = True

        # todo fire login event
        # todo add logger
        self.login()

    def onFrontDisconnected(self, n):
        """
        前置服务器断开
        """
        self.isConnected = False
        self.isLogin = False

        # todo add logger

    def onHeartBeatWarning(self, n):
        """心跳回调函数"""

        # API 已废弃
        pass

    def onRspError(self, error, n, last):
        """
        错误信息回调函数
        :param error:
        :param n:
        :param last:
        :return:
        """

        # todo add error event & logger

    def onRspUserLogin(self, data, error, n, last):
        """
        登录成功回调
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # 登录成功
        if error['ErrorID'] == 0:
            self.loginStatus = True

            # todo fire login success event & logger

            # 重新订阅合约
            for subscribeReq in self.subscribedSymbols:
                self.subscribe(subscribeReq)

        # 登录失败
        # todo add error event & logger
        else:
            pass

    def onRspSubMarketData(self, data, error, n, last):
        """
        合约订阅信息回调
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRspUnSubMarketData(self, data, error, n, last):
        """
        合约退订信息回调
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRtnDepthMarketData(self, data):
        """
        tick行情推送
        :param data:
        :return:
        """

        # todo Tick数据 & tick event & logger
        pass

    def onRspSubForQuoteRsp(self, data, error, n, last):
        """
        订阅期权询价回调
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        # 期权交易相关
        pass

    def onRspUnSubForQuoteRsp(self, data, error, n, last):
        """
        期权询价退订
        :param data:
        :param error:
        :param n:
        :param last:
        :return:
        """
        pass

    def onRtnForQuoteRsp(self, data):
        """
        期权询价推送
        :param data:
        :return:
        """
        pass

    def connect(self, userID, password, brokerID, address):
        """
        初始化连接
        :param userID:
        :param password:
        :param brokerID:
        :param address:
        :return:
        """

        self.userID = userID
        self.password = password
        self.brokerID = brokerID
        self.address = address

        # 如果当前未建立连接，则连接服务器
        if not self.isConnected:
            # 传入保存.con文件的路径, 入口文件的相对目录
            # todo 系统安装目录的绝对路径
            path = os.getcwd() + '/var/temp/ctp/futures/'
            if not os.path.exists(path):
                os.makedirs(path)

            self.createFtdcMdApi(path)

            # 注册前置服务器地址
            self.reisterFront(self.address)

            # 初始化连接
            self.init()

        # 若已经建立连接但尚未登录，则进行登录

        else:

            if not self.isLogin:
                self.login()

    def subscribe(self, subscribeReq):
        """
        订阅合约
        :param subscribeReq:
        :return:
        """

        if self.loginStatus:
            self.subscribeMarketData(str(subscribeReq.symbol))
        else:
            self.subscribedSymbols.add(subscribeReq)

    def login(self):
        """
        用户登录
        :return:
        """
        if self.userID and self.password and self.brokerID:
            req = {
                'UserID': self.userID,
                'Password': self.password,
                'BrokerID': self.brokerID
            }
            self.reqID += 1
            self.reqUserLogin(req, self.reqID)
        else:
            # todo add error
            pass

    def logout(self):
        """
        用户退出
        :return:
        """

        if self.userID and self.brokerID
            req = {
                'UserID': self.userID,
                'BrokerID': self.brokerID
            }
            self.reqID += 1
            self.reqUserLogout(req, self.reqID)

    def close(self):
        """
        关闭与服务器连接
        :return:
        """

        self.exit()







