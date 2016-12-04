# encoding: UTF-8
"""
CTP柜台接口测试
"""

from heron.lib.vnpy.gateway.ctp import CtpGateway
from heron.lib.vnpy.event import EventEngine
from heron.lib.vnpy.event.type import EVENT_LOG

import unittest
from time import sleep


def print_log(event):
    log = event.dict_['data']
    print u":".join([log.logTime, log.logContent]).encode('utf-8')


class TestCtpGateway(unittest.TestCase):

    def setUp(self):
        self.event_engine = EventEngine()
        self.event_engine.start()
        self.event_engine.register(EVENT_LOG, print_log)
        self.gateway = CtpGateway(self.event_engine)

    def test_connect_close(self):

        self.gateway.connect()

        sleep(3)

        self.assertTrue(self.gateway.mdConnected)
        self.assertTrue(self.gateway.tdConnected)

        sleep(5)

        self.gateway.close()

        sleep(5)

        self.assertFalse(self.gateway.mdConnected)
        self.assertFalse(self.gateway.tdConnected)
