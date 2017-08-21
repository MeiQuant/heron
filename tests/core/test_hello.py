#!/Users/alfred/anaconda/bin/python
# encoding: UTF-8
"""

"""
from __future__ import print_function
from time import sleep

from heron import Component, Event


class hello(Event):
    """hello Event"""

    num = 0

    def set_num(self, i):
        self.num = i


class terminate(Event):
    """terminate Event"""


class eventObj(object):
    def __init__(self):
        self.a = "a"
        self.b = "b"


class App(Component):

    def hello(self, event):
        """Hello Event Handler"""

        print("Hello World! and i am %d" % event.num)

    def started(self, *args):
        """Started Event Handler

        This is fired internally when your application starts up
        and can be used to trigger events that only occur once
        during startup.
        """

        print("i am here")

        for i in range(10):
            # sleep(0.1)
            # h = hello()
            # h.num = i
            h = hello()
            h.num = i
            self.fire(h)
        # Fire hello Event

        # self.fire(hello())

        # self.fire(terminate())

    def terminate(self):
        raise SystemExit(0)  # Terminate the Application

app = App()

app.start()

