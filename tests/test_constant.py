# encoding: UTF-8

"""
常量测试
"""

import heron.lib.vnpy.constant as constant

import unittest


class TestConstant(unittest.TestCase):

    def test_constant_value(self):

        self.assertEqual(constant.CURRENCY_CNY, 'CNY')

    def test_setter(self):
        with self.assertRaises(constant._Const.ConstError):
            constant.CURRENCY_CNY = 'aaa'

        with self.assertRaises(constant._Const.ConstCaseError):
            constant.abc = 'abc'


if __name__ == '__main__':
    unittest.main()
