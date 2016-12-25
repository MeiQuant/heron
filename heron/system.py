# encoding: UTF-8
"""
system事件监听

绑定与该namespace有关的监听，以响应客户端的请求
向engine注册与该namespace有关的Handler，以响应柜台事件
"""

from flask_socketio import Namespace

from heron.lib.vnpy.model import Log
from heron.lib.vnpy.event.type import EVENT_LOG, EVENT_ERROR


class SystemNamespace(Namespace):

    def __init__(self, engine, namespace='/system'):
        super(Namespace, self).__init__(namespace)
        self.engine = engine

        self.register_events()

    def send_log(self, event):
        log = event.dict_['model']
        self.emit('log', log.__dict__)

    def register_events(self):
        self.engine.eventEngine.register(EVENT_LOG, self.send_log)
        self.engine.eventEngine.register(EVENT_ERROR, self.send_log)

    def on_start(self, config):

        # todo 依据传入的柜台服务器地址建立连接
        self.engine.connect('CTP', config)

        # connect Database
        self.engine.dbConnect()

        log = Log()
        log.content = "system starting"
        self.emit('log', log.__dict__)

    def on_close(self):
        self.engine.exit()
        log = Log()
        log.content = "system closed"
        self.emit('log', log.__dict__)
