# encoding: UTF-8
"""
trade事件监听
"""

from flask_socketio import Namespace

from heron.lib.vnpy.model import Log, OrderReq, CancelOrderReq
from heron.lib.vnpy.event.type import EVENT_ORDER, EVENT_TRADE, EVENT_POSITION


class TradeNamespace(Namespace):

    def __init__(self, engine, namespace='/trade'):
        super(Namespace, self).__init__(namespace)
        self.engine = engine

        self.register_events()

    # rtn order
    def update_order(self, event):
        order_response = event.dict_['model']
        self.emit('update_order', order_response.__dict__)

    # trade information
    def update_trade(self, event):
        trade_response = event.dict_['model']
        self.emit('update_trade', trade_response.__dict__)

    # position information
    def update_position(self, event):
        position = event.dict_['model']
        position.msg = 'i am testing hot modify'
        self.emit('update_position', position.__dict__)

    def register_events(self):

        # 注册订单事件, 订单返回消息
        self.engine.eventEngine.register(EVENT_ORDER, self.update_order)

        # 注册成交事件，返回成交信息
        self.engine.eventEngine.register(EVENT_TRADE, self.update_trade)

        # 注册持仓变更事件，返回持仓信息
        self.engine.eventEngine.register(EVENT_POSITION, self.update_position)

    # send order
    def on_send_order(self, data):

        order_req = OrderReq()
        order_req.symbol = str(data['symbol'])
        order_req.price = data['price']
        order_req.volume = data['volume']
        order_req.priceType = data['priceType']
        order_req.direction = data['direction']
        order_req.offset = data['offset']
        self.engine.sendOrder(order_req, 'CTP')

    def on_cancel_order(self, order):

        req = CancelOrderReq()
        req.symbol = str(order['symbol'])
        req.exchange = str(order['exchange'])
        req.frontID = order['frontID']
        req.sessionID = order['sessionID']
        req.orderID = str(order['orderID'])
        self.engine.cancelOrder(req, 'CTP')

    def on_cancel_all(self):

        working_orders = self.engine.getAllWorkingOrders()
        for order in working_orders:
            req = CancelOrderReq()
            req.symbol = str(order.symbol)
            req.exchange = str(order.exchange)
            req.frontID = order.frontID
            req.sessionID = order.sessionID
            req.orderID = str(order.orderID)
            self.engine.cancelOrder(req, 'CTP')

    def on_get_position(self):

        self.engine.qryPosition()
        # socketio.emit('update_position', positions.__dict__)
        log = Log()
        log.content = u"已经开始查询持仓信息"
        self.emit('log', log.__dict__, namespace='/system')
