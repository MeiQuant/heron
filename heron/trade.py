# encoding: UTF-8
"""
trade事件监听
"""

from flask_socketio import Namespace

from heron.lib.vnpy.data import Log, OrderReq, CancelOrderReq


class TradeNamespace(Namespace):

    def __init__(self, namespace, engine):
        super(Namespace, self).__init__(namespace)
        self.engine = engine

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
