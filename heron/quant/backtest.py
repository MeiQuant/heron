# encoding: UTF-8
"""
回测工具，获取行情，发送事件
"""

import datetime

from heron.data import DataReader


def backtest(strategy, start, end=None, period="D"):
    """
    bactest method: backtest one strategy during start & end in period
    :param strategy, component
    :param start, python datetime object
    :param end, python datetime object
    :param period, eum("D", "M")
    :return
    """

    if end is None:
        end = datetime.datetime.now()

    dr = DataReader()

    symbols = strategy.symbols

    data = dr.get_hist(symbols, start, end)

    for bar in data:
        strategy.fire(bar)

