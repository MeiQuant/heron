# encoding: UTF-8
"""

"""

import unittest
import os
from threading import current_thread
from time import sleep

from heron import Manager, Component


class App(Component):

    def test(self, *args):
        return "Hello World!"


class TestManager(unittest.TestCase):

    def setUp(self):

        self.manager = Manager()

    def test_start(self):
        self.manager.start()
        # use property to access running status
        self.assertTrue(self.manager._running)
        self.assertIsNotNone(self.manager.pid)
        self.assertEqual(self.manager.name, "Manager")

    def test_stop(self):
        self.manager.stop()
        self.assertFalse(self.manager.running)

    def test_method(self):

        id = "%s:%s" % (os.getpid(), current_thread().getName())

        m = Manager()
        s = repr(m)
        self.assertEqual(s, "<Manager %s (queued=0) [S]>" % id)

        app = App()

        # add two component to the Manager
        app2 = App()
        app.use(app2)

        app.register(m)
        s = repr(m)
        self.assertEqual(s, "<Manager %s (queued=2) [S]>" % id)

        m.start()

        # wait for start
        sleep(0.1)

        self.assertTrue(m.running)

        s = repr(m)
        self.assertEqual(s, "<Manager %s (queued=0) [R]>" % id)

        m.stop()

        # wait for stop
        sleep(2)

        s = repr(m)
        self.assertEqual(s, "<Manager %s (queued=0) [S]>" % id)

if __name__ == '__main__':
    unittest.main()
