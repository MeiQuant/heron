# encoding: UTF-8
"""
测试map字段的获取
"""

from heron.lib.vnpy.gateway.ctp.mapping import *

import unittest


class TestMapping(unittest.TestCase):
    def test_mapping(self):
        price_type = priceTypeMap.get(u'限价')
        print price_type
        self.assertEqual(price_type, '2')

if __name__ == '__main__':
    unittest.main()
