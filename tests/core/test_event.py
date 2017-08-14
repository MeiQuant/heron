# encoding: UTF-8
"""

"""

import unittest

from heron import Component, Event


class test(Event):

    """test Event"""


class App(Component):

    def test(self):
        return "Hello World!"


class TestEvent(unittest.TestCase):

    def test_repr(self):
        app = App()
        while len(app):
            app.flush()

        e = test()

        s = repr(e)
        self.assertEqual(s, "<test ( )>")

        app.fire(e)

        s = repr(e)
        self.assertEqual(s, "<test ( )>")

    def test_create(self):
        app = App()
        while len(app):
            app.flush()

        e = Event.create("test")

        s = repr(e)
        self.assertEqual(s, "<test ( )>")

        app.fire(e)

        s = repr(e)
        self.assertEqual(s, "<test ( )>")

    def test_getitem(self):
        app = App()
        while len(app):
            app.flush()

        e = test(1, 2, 3, foo="bar")

        assert e[0] == 1
        assert e["foo"] == "bar"

        def f(e, k):
            return e[k]

        self.assertRaises(TypeError, f, e, None)

    def test_setitem(self):
        app = App()
        while len(app):
            app.flush()

        e = test(1, 2, 3, foo="bar")

        assert e[0] == 1
        assert e["foo"] == "bar"

        e[0] = 0
        e["foo"] = "Hello"

        def f(e, k, v):
            e[k] = v

        self.assertRaises(TypeError, f, e, None, None)

        assert e[0] == 0
        assert e["foo"] == "Hello"


if __name__ == '__main__':
    unittest.main()
