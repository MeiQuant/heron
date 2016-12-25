# encoding: UTF-8
"""
发单请求类
"""

from heron.lib.vnpy.constant import EMPTY_FLOAT, EMPTY_STRING, EMPTY_UNICODE, EMPTY_INT


class OrderReq(object):
    """发单时传入的对象类"""

    def __init__(self):
        """Constructor"""
        self.symbol = EMPTY_STRING              # 代码
        self.exchange = EMPTY_STRING            # 交易所
        self.price = EMPTY_FLOAT                # 价格
        self.volume = EMPTY_INT                 # 数量

        self.priceType = EMPTY_STRING           # 价格类型
        self.direction = EMPTY_STRING           # 买卖
        self.offset = EMPTY_STRING              # 开平

        # 以下为IB相关
        self.productClass = EMPTY_UNICODE       # 合约类型
        self.currency = EMPTY_STRING            # 合约货币
        self.expiry = EMPTY_STRING              # 到期日
        self.strikePrice = EMPTY_FLOAT          # 行权价
        self.optionType = EMPTY_UNICODE         # 期权类型