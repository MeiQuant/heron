# encoding: UTF-8

"""
常量定义

增加了常量的约束条件

"""
import sys
import constant


class _Const:
    """常量限制类"""
    def __init__(self):
        pass

    class ConstError(TypeError):
        def __init__(self):
            pass
        pass

    class ConstCaseError(ConstError):
        def __init__(self):
            pass
        pass

    def __setattr__(self, key, value):
        if self.__dict__.has_key(key):
            raise self.ConstError, "Can't change const. %s" % key
        if not key.isupper():
            raise self.ConstCaseError, "const name %s is not all uppercase" % key
        self.__dict__[key] = value

sys.modules[__name__] = _Const()

# 默认空值
constant.EMPTY_STRING = ''
constant.EMPTY_UNICODE = u''
constant.EMPTY_INT = 0
constant.EMPTY_FLOAT = 0.0

# 方向常量
constant.DIRECTION_NONE = u'无方向'
constant.DIRECTION_LONG = u'多'
constant.DIRECTION_SHORT = u'空'
constant.DIRECTION_UNKNOWN = u'未知'
constant.DIRECTION_NET = u'净'
constant.DIRECTION_SELL = u'卖出'      # IB接口

# 开平常量
constant.OFFSET_NONE = u'无开平'
constant.OFFSET_OPEN = u'开仓'
constant.OFFSET_CLOSE = u'平仓'
constant.OFFSET_CLOSETODAY = u'平今'
constant.OFFSET_CLOSEYESTERDAY = u'平昨'
constant.OFFSET_UNKNOWN = u'未知'

# 状态常量
constant.STATUS_NOTTRADED = u'未成交'
constant.STATUS_PARTTRADED = u'部分成交'
constant.STATUS_ALLTRADED = u'全部成交'
constant.STATUS_CANCELLED = u'已撤销'
constant.STATUS_UNKNOWN = u'未知'

# 合约类型常量
constant.PRODUCT_EQUITY = u'股票'
constant.PRODUCT_FUTURES = u'期货'
constant.PRODUCT_OPTION = u'期权'
constant.PRODUCT_INDEX = u'指数'
constant.PRODUCT_COMBINATION = u'组合'
constant.PRODUCT_FOREX = u'外汇'
constant.PRODUCT_UNKNOWN = u'未知'
constant.PRODUCT_SPOT = u'现货'
constant.PRODUCT_DEFER = u'延期'
constant.PRODUCT_NONE = ''

# 价格类型常量
constant.PRICETYPE_LIMITPRICE = u'限价'
constant.PRICETYPE_MARKETPRICE = u'市价'
constant.PRICETYPE_FAK = u'FAK'
constant.PRICETYPE_FOK = u'FOK'

# 期权类型
constant.OPTION_CALL = u'看涨期权'
constant.OPTION_PUT = u'看跌期权'

# 交易所类型
constant.EXCHANGE_SSE = 'SSE'       # 上交所
constant.EXCHANGE_SZSE = 'SZSE'     # 深交所
constant.EXCHANGE_CFFEX = 'CFFEX'   # 中金所
constant.EXCHANGE_SHFE = 'SHFE'     # 上期所
constant.EXCHANGE_CZCE = 'CZCE'     # 郑商所
constant.EXCHANGE_DCE = 'DCE'       # 大商所
constant.EXCHANGE_SGE = 'SGE'       # 上金所
constant.EXCHANGE_UNKNOWN = 'UNKNOWN'# 未知交易所
constant.EXCHANGE_NONE = ''          # 空交易所
constant.EXCHANGE_HKEX = 'HKEX'      # 港交所

constant.EXCHANGE_SMART = 'SMART'       # IB智能路由（股票、期权）
constant.EXCHANGE_NYMEX = 'NYMEX'       # IB 期货
constant.EXCHANGE_GLOBEX = 'GLOBEX'     # CME电子交易平台
constant.EXCHANGE_IDEALPRO = 'IDEALPRO' # IB外汇ECN

constant.EXCHANGE_CME = 'CME'           # CME交易所
constant.EXCHANGE_ICE = 'ICE'           # ICE交易所

constant.EXCHANGE_OANDA = 'OANDA'       # OANDA外汇做市商
constant.EXCHANGE_OKCOIN = 'OKCOIN'     # OKCOIN比特币交易所

# 货币类型
constant.CURRENCY_USD = 'USD'            # 美元
constant.CURRENCY_CNY = 'CNY'            # 人民币
constant.CURRENCY_UNKNOWN = 'UNKNOWN'    # 未知货币
constant.CURRENCY_NONE = ''              # 空货币