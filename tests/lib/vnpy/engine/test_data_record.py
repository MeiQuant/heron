# encoding: UTF-8
"""
数据记录引擎测试
"""

import unittest

from heron.lib.vnpy.engine.data_record import DataRecordEngine
from heron.lib.vnpy.engine.main import MainEngine

class TestDataRecordEngine(unittest.TestCase):


    def setUp(self):

        main_engine = MainEngine()

        data_record_enginge = DataRecordEngine(main_engine, main_engine.eventEngine)

    def test_something(self):
        self.assertEqual(True, True)


if __name__ == '__main__':
    unittest.main()
