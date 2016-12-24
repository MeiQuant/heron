# encoding: UTF-8

"""
业务开始

登录柜台

建立socket.io server

承担client到柜台的转发

"""

from flask import Flask
from flask_socketio import SocketIO
import eventlet

from heron.lib.vnpy.engine.main import MainEngine

from system import SystemNamespace
from market import MarketNamespace
from trade import TradeNamespace

# patch the socket module by eventlet to support multiple workers
eventlet.monkey_patch(socket=True)

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app, engineio_logger=True, logger=True)

engine = MainEngine()

socketio.on_namespace(SystemNamespace('/system', engine))
socketio.on_namespace(TradeNamespace('/trade', engine))
socketio.on_namespace(MarketNamespace('/market', engine))


def start():
    print 'start server...'
    socketio.run(app, host='192.168.33.10')

