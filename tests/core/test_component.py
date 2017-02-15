# encoding: UTF-8
"""

"""

import unittest

from heron import Component


class Pound(Component):

    def __init__(self):
        super(Pound, self).__init__()

        self.bob = Bob().register(self)
        self.fred = Fred().register(self)

    def started(self):
        print self.root


class Bob(Component):

    def started(self):
        print "Hello I'm Bob!"


class Fred(Component):

    def started(self):
        print "Hello I'm Fred!"


class TestHeron(unittest.TestCase):

    def setUp(self):
        pass

    def test_inheritance(self):
        self.assertIsInstance(Pound(), Component)

if __name__ == '__main__':
    unittest.main()