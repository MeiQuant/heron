# encoding: UTF-8
"""
对设置文件的读取进行测试
"""

from heron.lib.vnpy.settings import load_setting

import unittest


class TestLoadSetting(unittest.TestCase):

    # 测试读取

    def test_load_file_nokey(self):

        with self.assertRaises(IOError):
            load_setting('nokey')

    def test_load_value(self):
        setting = load_setting('CTP')

        self.assertIsNotNone(setting)

        self.assertEqual(setting['brokerID'], "9999")

