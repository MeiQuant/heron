# encoding: UTF-8
"""

"""

import unittest

from heron import Heron
from heron.core import BaseComponent
from heron.core.manager import Manager


class TestHeron(unittest.TestCase):

    def setUp(self):
        self.app = Heron()

    def test_inheritance(self):
        self.assertIsInstance(self.app, BaseComponent)
        self.assertIsInstance(self.app, Manager)

if __name__ == '__main__':
    unittest.main()
