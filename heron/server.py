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
from heron.lib.vnpy.event.type import EVENT_LOG


app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)

dict = {}

# send log to client
def send_log(self, event):
    log = event.dict_['data']
    socketio.emit('log', log.to_json())


# start engine and connect to counter
@socketio.on('system_start')
def on_start(data):

    engine = MainEngine()

    # 注册日志事件
    engine.eventEngine.register(EVENT_LOG, send_log)

    engine.connect('CTP')

    dict['engine'] = engine


@socketio.on('system_exit')
def on_close(data):

    if 'engine' in dict:
        dict['engine'].exit()
    else:

        socketio.emit('log', {})


@socketio.on('connect')
def on_connect():
    print('connected')


def start():
    print 'start server...'
    socketio.run(app, host='192.168.33.10')




