# encoding: UTF-8

"""
常量测试
"""

import heron.lib.vnpy.constant as constant

from heron.lib.utils import ConstantBase

import unittest


class TestConstant(unittest.TestCase):

    # 保证constant单例
    def test_constant_instance(self):
        self.assertIsInstance(constant, ConstantBase)

    # todo 测试更多常量的值
    def test_constant_value(self):

        self.assertEqual(constant.CURRENCY_CNY, 'CNY')

    def test_setter(self):
        with self.assertRaises(TypeError):
            constant.CURRENCY_CNY = 'aaa'

        with self.assertRaises(TypeError):
            constant.abc = 'abc'

