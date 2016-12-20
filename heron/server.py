# encoding: UTF-8

"""
业务开始

登录柜台

建立socket.io server

承担client到柜台的转发

"""

from flask import Flask
from flask_socketio import SocketIO

from heron.lib.vnpy.engine.main import MainEngine
from heron.lib.vnpy.event.type import EVENT_LOG, EVENT_TICK, EVENT_ERROR, EVENT_ORDER, EVENT_TRADE, EVENT_POSITION
from heron.lib.vnpy.data import Log, SubscribeReq, OrderReq, CancelOrderReq


# import pydevd

# pydevd.settrace('192.168.1.11', port=2333, stdoutToServer=True, stderrToServer=True)

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app, engineio_logger=True, logger=True)

dicts = {}


# subscribe All
def subscribe_all(engine):
    contracts = engine.dataEngine.getAllContracts()

    for contract in contracts:
        subscribe_req = SubscribeReq()
        subscribe_req.symbol = contract.symbol
        subscribe_req.currency = 'CHY'
        subscribe_req.productClass = contract.productClass

        engine.subscribe(subscribe_req, 'CTP')


# send log to client
def send_log(event):
    log = event.dict_['data']
    socketio.emit('log', log.__dict__, namespace='/system')


# send ticks to client
def update_tick(event):
    tick = event.dict_['data']
    # todo 转成有序数组发送给客户端
    socketio.emit('update_tick', tick.__dict__, namespace='/market')


# rtn order
def update_order(event):
    order_response = event.dict_['data']
    socketio.emit('update_order', order_response.__dict__, namespace='/trade')


# trade information
def update_trade(event):
    trade_response = event.dict_['data']
    socketio.emit('update_trade', trade_response.__dict__, namespace='/trade')


# position information
def update_position(event):
    postion = event.dict_['data']
    socketio.emit('update_position', postion.__dict__, namespace='/trade')


# register events
def register_events(engine):
    # 注册日志与错误事件
    engine.eventEngine.register(EVENT_LOG, send_log)
    engine.eventEngine.register(EVENT_ERROR, send_log)

    # 注册行情事件
    # engine.eventEngine.register(EVENT_TICK, update_tick)

    # 注册订单事件, 订单返回消息
    engine.eventEngine.register(EVENT_ORDER, update_order)

    # 注册成交事件，返回成交信息
    engine.eventEngine.register(EVENT_TRADE, update_trade)

    # 注册持仓变更事件，返回持仓信息
    engine.eventEngine.register(EVENT_POSITION, update_position)


# subscribe contract
@socketio.on('subscribe', namespace='/market')
def on_subscribe(data):
    if 'engine' in dicts:
        engine = dicts['engine']
        subscribe_req = SubscribeReq()
        subscribe_req.symbol = data['symbol']
        subscribe_req.currency = 'CHY'
        subscribe_req.productClass = data['productClass']
        engine.subscribe(subscribe_req, 'CTP')
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# subscribe contract
@socketio.on('subscribe_all', namespace='/market')
def on_subscribe_all():
    if 'engine' in dicts:
        subscribe_all(dicts['engine'])


# send order
@socketio.on('send_order', namespace='/trade')
def send_order(data):
    if 'engine' in dicts:
        engine = dicts['engine']
        order_req = OrderReq()
        order_req.symbol = str(data['symbol'])
        order_req.price = data['price']
        order_req.volume = data['volume']
        order_req.priceType = data['priceType']
        order_req.direction = data['direction']
        order_req.offset = data['offset']
        engine.sendOrder(order_req, 'CTP')
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# cancel all working order
@socketio.on('cancel_order', namespace='/trade')
def cancel_order(order):
    if 'engine' in dicts:
        engine = dicts['engine']
        req = CancelOrderReq()
        req.symbol = str(order['symbol'])
        req.exchange = str(order['exchange'])
        req.frontID = order['frontID']
        req.sessionID = order['sessionID']
        req.orderID = str(order['orderID'])
        engine.cancelOrder(req, 'CTP')
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# cancel all working order
@socketio.on('cancel_all', namespace='/trade')
def cancel_all():
    if 'engine' in dicts:
        engine = dicts['engine']
        working_orders = engine.getAllWorkingOrders()
        for order in working_orders:
            req = CancelOrderReq()
            req.symbol = str(order.symbol)
            req.exchange = str(order.exchange)
            req.frontID = order.frontID
            req.sessionID = order.sessionID
            req.orderID = str(order.orderID)
            engine.cancelOrder(req, 'CTP')
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# positions
@socketio.on('get_position', namespace='/trade')
def get_position():
    if 'engine' in dicts:
        engine = dicts['engine']
        engine.qryPosition()
        # socketio.emit('update_position', positions.__dict__)
        log = Log()
        log.content = u"已经开始查询持仓信息"
        socketio.emit('log', log.__dict__, namespace='/system')
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# start engine and connect to counter
@socketio.on('system_start', namespace='/system')
def on_start():

    engine = MainEngine()

    engine.connect('CTP')

    dicts['engine'] = engine

    register_events(engine)

    # 订阅所有合约行情
    subscribe_all(engine)

    log = Log()
    log.content = "system starting"
    socketio.emit('log', log.__dict__, namespace='/system')


@socketio.on('system_exit', namespace='/system')
def on_close():

    if 'engine' in dicts:
        dicts['engine'].exit()
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


@socketio.on('connect')
def on_connect():
    print('connected')


def start():
    print 'start server...'
    socketio.run(app, host='192.168.33.10')
    # socketio.run(app)
