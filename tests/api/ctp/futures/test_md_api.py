# encoding: UTF-8
"""

"""

import unittest
import os
from time import sleep

from heron.api.ctp.futures.MdApi import MdApi


class Adapter(MdApi):

    def __init__(self):
        super(Adapter, self).__init__()
        self.connect_status = False

    def connect(self):

        self.createFtdcMdApi(os.getcwd())

        self.registerFront('tcp://180.168.146.187:10010')

    def onFrontConnected(self):
        self.connect_status = True
        print 'front success'


class TestMdApi(unittest.TestCase):

    def setUp(self):
        self.adapter = Adapter()
        self.adapter.connect()
        self.adapter.init()

    def test_connect(self):

        sleep(1)

        self.assertEqual(self.adapter.connect_status, True)


if __name__ == '__main__':
    unittest.main()
