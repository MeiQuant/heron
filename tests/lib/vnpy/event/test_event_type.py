# encoding: UTF-8
"""
事件类型常量测试
"""

import heron.lib.vnpy.event.type as event_type

import unittest


class TestEventType(unittest.TestCase):

    def test_event_type_getter(self):

        self.assertEqual(event_type.EVENT_LOG, 'eLog')