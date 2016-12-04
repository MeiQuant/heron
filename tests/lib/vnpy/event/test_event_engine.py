# encoding: UTF-8
"""
测试事件引擎
"""

from datetime import datetime
from time import sleep

from heron.lib.vnpy.event import EventEngine, Event
from heron.lib.vnpy.event.type import EVENT_LOG, EVENT_TIMER
from heron.lib.vnpy.data import Log


import unittest


def simpletest(event):
    print "event every second：%s" % str(datetime.now())


def print_log(event):
    log = event.dict_['data']
    print ':'.join([log.logTime, log.logContent])


class TestEventEnggine(unittest.TestCase):

    def setUp(self):
        self.event_engine = EventEngine()
        self.event_engine.start()

    def test_event_engine(self):

        self.event_engine.register(EVENT_TIMER, simpletest)
        self.event_engine.register(EVENT_LOG, print_log)

        log = Log()
        log.logContent = "\nThis is log from event engine test!!!!"

        event = Event(type_=EVENT_LOG)
        event.dict_['data'] = log

        self.event_engine.put(event)

        sleep(5)

        # print five lines by simpletest and then quit
        self.event_engine.stop()
