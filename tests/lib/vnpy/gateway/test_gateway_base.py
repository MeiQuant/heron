# encoding: UTF-8
"""
接口基类测试
"""

from heron.lib.vnpy.gateway.gateway_base import GatewayBase
from heron.lib.vnpy.event import EventEngine
from heron.lib.vnpy.event.type import EVENT_LOG
from heron.lib.vnpy.model import Log

import unittest
from time import sleep


class Gateway(GatewayBase):

    def __init__(self, event_engine, gateway_name):
        super(Gateway, self).__init__(event_engine, gateway_name)


def print_log(event):
    log = event.dict_['model']
    print u":".join([log.time, log.logContent]).encode('utf-8')


class TestGatwayBase(unittest.TestCase):

    def setUp(self):
        self.event_engine = EventEngine()
        self.event_engine.start()
        self.event_engine.register(EVENT_LOG, print_log)
        self.gateway = Gateway(self.event_engine, 'Name')

    def test_inherit(self):

        self.assertIsInstance(self.gateway, GatewayBase)

        self.assertEqual(self.gateway.gatewayName, 'Name')

    def test_method(self):

        log = Log()
        log.logContent = u"\nThis is log from GatewayBase test!!!! 这是GatewayBase测试脚本输出的日志"

        self.gateway.onLog(log)

        sleep(2)

        self.event_engine.stop()


