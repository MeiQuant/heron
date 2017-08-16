#!/usr/bin/env python
# encoding: UTF-8
"""

"""

import unittest

from heron import Component, Event


class foo(Event):

    """foo Event"""


class done(Event):

    """done Event"""


class App(Component):

    def init(self):
        self.results = []

    def foo(self, value):
        self.results.append(value)

    def done(self):
        self.stop()


class TestEventPriority(unittest.TestCase):

    def test_normal(self):
        app = App()

        # Normal Order
        [app.fire(foo(1)), app.fire(foo(2))]
        app.fire(done())

        app.run()

        assert app.results == [1, 2]

    def test_priority(self):
        app = App()

        # Priority Order
        [app.fire(foo(3), priority=2), app.fire(foo(4), priority=0)]
        app.fire(done())

        app.run()

        assert app.results == [4, 3]
