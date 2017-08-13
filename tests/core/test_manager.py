# encoding: UTF-8
"""

"""

import unittest

from heron.core.manager import Manager


class TestManager(unittest.TestCase):

    def setUp(self):

        self.manager = Manager()

    def test_start(self):
        self.manager.start()
        assert self.manager._running

    def test_stop(self):
        self.manager.stop()
        assert not self.manager._running


if __name__ == '__main__':
    unittest.main()
