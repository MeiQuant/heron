import unittest


from heron import quant
from heron import Event


class Tick2(Event):
    """
    tick event
    """

    def __init__(self, data, data2):
        self.data = data
        super(Tick2, self).__init__(data, data2)


class TestQuant(unittest.TestCase):

    def test_backtest(self):

        self.assertEqual(quant.backtest(), "I am backtest method")

    def test_event_handler(self):

        # tick = Tick("data", "data2")

        tick = Tick2("data2", "data2")

        quant.fire(tick)

        quant.flush()

        self.assertEqual(tick.data, "data2")

        quant.stop()


if __name__ == '__main__':
    unittest.main()
