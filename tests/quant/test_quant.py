import unittest


from heron import quant
from heron import Event


class Tick(Event):
    """
    tick event
    """

    def __init__(self, data, data2):
        self.data = data
        super(Tick, self).__init__(data, data2)


class TestQuant(unittest.TestCase):

    def test_backtest(self):

        self.assertEqual(quant.backtest(), "I am backtest method")

    def test_event_handler(self):

        # tick = Tick("data", "data2")

        tick = Tick("data10", "data2")

        quant.fire(tick)

        quant.flush()

        # tick handler change the data value to data11

        self.assertEqual(tick.data, "data11")

        quant.stop()


if __name__ == '__main__':
    unittest.main()
