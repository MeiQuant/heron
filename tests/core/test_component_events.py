# encoding: UTF-8
"""
测试组件的事件引擎
"""

from heron import Component
from heron.core.events import Event


class foo(Event):

    """foo Event"""


class done(Event):

    """done Event"""


class App(Component):

    def init(self):
        self.results = []

    def foo(self, value):
        self.results.append(value)

    # 必须显式的调用stop，以保证Manager的run正确返回
    def done(self):
        self.stop()


def test1():
    app = App()

    # Normal Order
    [app.fire(foo(1)), app.fire(foo(2))]
    app.fire(done())

    app.run()

    assert app.results == [1, 2]


def test2():
    app = App()

    # Priority Order
    [app.fire(foo(1), priority=2), app.fire(foo(2), priority=0)]
    app.fire(done())

    app.run()

    assert app.results == [2, 1]


def test3():

    app = App()

    app.fire(foo('fired'))
    app.fire(done())

    app.run()

    assert app.results == ['fired']
