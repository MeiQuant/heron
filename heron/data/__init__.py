# encoding: UTF-8
"""
Data Module provides an interface for all subsequent (inherited)
data handlers (both live and historic).

When getting the live market quote, should integrates with adapter module.

The goal of a (derived) Data object is to output a generated
set of bars (OLHCVI) for each symbol requested.

This will replicate how a live strategy would function as current
market data would be sent "down the pipe". Thus a historic and live
system will be treated identically by the rest of the backtesting suite.
"""

from reader import DataReader