# encoding: UTF-8
"""
market事件监听
"""

import re

from flask_socketio import Namespace


from heron.lib.vnpy.model import SubscribeReq
from heron.lib.vnpy.event.type import EVENT_TICK


class MarketNamespace(Namespace):

    def __init__(self, engine, namespace='/data'):
        super(Namespace, self).__init__(namespace)
        self.engine = engine

        self.register_events()

        # 默认订阅所有合约
        self.subscribe_all_options()

    def subscribe_all(self):

        contracts = self.engine.dataEngine.getAllContracts()

        for contract in contracts:
            subscribe_req = SubscribeReq()
            subscribe_req.symbol = contract.symbol
            subscribe_req.currency = 'CHY'
            subscribe_req.productClass = contract.productClass

            self.engine.subscribe(subscribe_req, 'CTP')

    def subscribe_all_options(self):

        # todo 这只是暂时的hack方法，等待客户端完善后移除
        contracts = self.engine.dataEngine.getAllContracts()

        pattern = re.compile('[12]', 0)

        for contract in contracts:

            if pattern.match(contract.symbol):
                subscribe_req = SubscribeReq()
                subscribe_req.symbol = contract.symbol
                subscribe_req.currency = 'CHY'
                subscribe_req.productClass = contract.productClass

                self.engine.subscribe(subscribe_req, 'CTP')
            else:
                continue

    def update_tick(self, event):
        tick = event.dict_['data']
        # todo 转成有序数组发送给客户端
        self.emit('update_tick', tick.__dict__)

    def register_events(self):
        # 注册行情事件
        self.engine.eventEngine.register(EVENT_TICK, self.update_tick)

    def on_subscribe(self, data):

        subscribe_req = SubscribeReq()
        subscribe_req.symbol = data['symbol']
        subscribe_req.currency = 'CHY'
        subscribe_req.productClass = data['productClass']
        self.engine.subscribe(subscribe_req, 'CTP')

    def on_subscribe_all(self):
        self.subscribe_all()
