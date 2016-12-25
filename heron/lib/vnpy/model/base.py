# encoding: UTF-8

"""
数据类型基类,其他数据类继承于此
"""

import json

from heron.lib.vnpy.constant import EMPTY_STRING


class Base(object):

    def __init__(self):

        self.gatewayName = EMPTY_STRING         # Gateway名称
        self.rawData = None                     # 原始数据

    def to_json(self):
        return json.dumps(self, default=lambda o: o.__dict__, sort_keys=True, indent=4)
