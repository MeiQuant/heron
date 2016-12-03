# encoding: UTF-8

"""
业务开始

登录柜台

建立socket.io server

承担client到柜台的转发

"""

from flask import Flask
from flask_socketio import SocketIO, emit

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)


@socketio.on('my_event')
def test_message(message):
    emit('my_response', {'data': 'got it!'})


@socketio.on('connect')
def handle_message(message):
    print('received message: ' + message)


def start():
    print 'start server...'
    socketio.run(app)




