# encoding: UTF-8
"""

"""

import unittest

from heron import Event, Component, Manager


class test(Event):

    """test Event"""


class terminate(Event):
    """terminate Event"""


class App(Component):

    tmp = "aa"

    def test(self, *args):
        self.tmp = "Hello World!"

    def unregistered(self, *args):
        return

    def prepare_unregister(self, *args):
        return


m = Manager()
app = App()
app.register(m)

while len(app):
    app.flush()


class TestCore(unittest.TestCase):

    def test_fire(self):
        x = m.fire(test())
        m.flush()
        self.assertEqual(app.tmp, "Hello World!")

    def test_contains(self):
        assert App in m
        assert m not in app

if __name__ == '__main__':
    unittest.main()
