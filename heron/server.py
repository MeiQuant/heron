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
from heron.lib.vnpy.event.type import EVENT_LOG, EVENT_TICK, EVENT_ERROR
from heron.lib.vnpy.data import Log, SubscribeReq


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


def send_tick_callback():

    print 'client has received'


# send ticks to client
def send_tick(event):
    tick = event.dict_['data']
    socketio.emit('update_tick', tick.__dict__, namespace='/market', callback=send_tick_callback)


# start engine and connect to counter
@socketio.on('system_start', namespace='/system')
def on_start(data):

    engine = MainEngine()

    # 注册日志与错误事件
    engine.eventEngine.register(EVENT_LOG, send_log)
    engine.eventEngine.register(EVENT_ERROR, send_log)

    # 注册行情事件
    engine.eventEngine.register(EVENT_TICK, send_tick)

    engine.connect('CTP')

    dicts['engine'] = engine

    # 订阅所有合约行情
    subscribe_all(engine)

    log = Log()
    log.content = "system start"
    socketio.emit('log', log.__dict__, namespace='/system')


@socketio.on('system_exit', namespace='/system')
def on_close(data):

    if 'engine' in dicts:
        dicts['engine'].exit()
    else:
        log = Log()
        log.content = u"当前没有运行的通信服务"
        socketio.emit('log', log.__dict__, namespace='/system')


# ping_pong维持链接
@socketio.on('my_ping', namespace='/system')
def ping_pong():
    socketio.emit('my_pong', {}, namespace='/system')


@socketio.on('connect')
def on_connect():
    print('connected')


def start():
    print 'start server...'
    socketio.run(app, host='192.168.33.10')
    # socketio.run(app)




