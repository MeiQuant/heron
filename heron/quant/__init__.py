# encoding: UTF-8
"""
策略研究组件，包含策略研究、回测等相关的工具包

Quant.bt = Quant.backtest

"""

from heron import BaseComponent


class Quant(BaseComponent):

    def backtest(self):

        print("I am backtest method")