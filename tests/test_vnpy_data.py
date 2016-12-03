# encoding: UTF-8

"""
数据类测试
"""

import unittest

from heron.lib.vnpy.data import Base, Tick, OrderReq


class TestConstant(unittest.TestCase):

    def test_base_inherit(self):

        tick = Tick()

        self.assertIsInstance(tick, Base)

    def test_tick_setter(self):

        tick = Tick()

        tick.askPrice1 = 100

        self.assertIsInstance(tick, Tick)

    def test_request_order(self):

        order_req = OrderReq()

        self.assertIsInstance(order_req, OrderReq)
