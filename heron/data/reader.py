# encoding: UTF-8
"""
数据读取器，传入参数，读取历史数据
"""

import pandas as pd


from heron import BaseComponent, Event, handler


class DataReader(BaseComponent):

    def __init__(self, *args, **kwargs):
        super(DataReader, self).__init__(*args, **kwargs)

        # todo

    def get_hist(self, symbols, start, end, options):
        """
        :return: pandas.DataFrame
        """

        return pd.DataFrame()
