# encoding: UTF-8
"""
market事件监听
"""

from flask_socketio import Namespace


from heron.lib.vnpy.data import SubscribeReq
from heron.lib.vnpy.event.type import EVENT_TICK


class MarketNamespace(Namespace):

    def __init__(self, namespace, engine):
        super(Namespace, self).__init__(namespace)
        self.engine = engine

        self.register_events()

    def update_tick(self, event):
        tick = event.dict_['data']
        # todo 转成有序数组发送给客户端
        self.emit('update_tick', tick.__dict__, namespace='/market')

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
        contracts = self.engine.dataEngine.getAllContracts()

        for contract in contracts:
            subscribe_req = SubscribeReq()
            subscribe_req.symbol = contract.symbol
            subscribe_req.currency = 'CHY'
            subscribe_req.productClass = contract.productClass

            self.engine.subscribe(subscribe_req, 'CTP')