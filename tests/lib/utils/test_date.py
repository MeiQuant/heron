# encoding: UTF-8
"""
时间工具函数测试
"""

from heron.lib.utils.date import today

import unittest


class test_date(unittest.TestCase):

    def test_today(self):

        t1 = today()
        t2 = today()

        self.assertEqual(t1, t2)