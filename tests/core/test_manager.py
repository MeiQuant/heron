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
        # use property to access running status
        self.assertTrue(self.manager.running)
        self.assertIsNotNone(self.manager.pid)
        self.assertEqual(self.manager.name, "Manager")

    def test_stop(self):
        self.manager.stop()
        self.assertFalse(self.manager.running)


if __name__ == '__main__':
    unittest.main()
