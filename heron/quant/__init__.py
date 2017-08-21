# encoding: UTF-8
"""
策略研究组件，包含策略研究、回测等相关的工具包

Quant.bt = Quant.backtest

"""

from heron import BaseComponent, handler, Event


class Tick(Event):
    """
    tick event
    """


class Signal(Event):
    """
    Handles the event of sending a Signal from a Strategy object.
    This is received by a Portfolio object and acted upon.
    """


class Fill(Event):
    """
    Encapsulates the notion of a Filled Order, as returned
    from a brokerage. Stores the quantity of an instrument
    actually filled and at what price. In addition, stores
    the commission of the trade from the brokerage.
    """


class Order(Event):
    """
    Handles the event of sending an Order to an execution system.
    The order contains a symbol (e.g. 510050.SH), a type (data or limit),
    quantity and a direction
    """


class Quant(BaseComponent):

    def __init__(self):
        super(Quant, self).__init__()
        self.data = None

    @handler("Tick2")
    def Tick2(self, data, data2):

        print data

        self.data = data

        return "i am a tick event handler"

    @handler("sigal")
    def signal(self):
        print("i am a signal event handler")

    def backtest(self):

        return "I am backtest method"

    def tick(self):

        return 'as'

quant = Quant()
