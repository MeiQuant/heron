# encoding: UTF-8
"""
事件类型常量

通过继承ConstantBase实现常量的定义

"""

import sys

from heron.lib.utils import ConstantBase


event_type = ConstantBase()

# 系统相关
event_type.EVENT_TIMER = 'eTimer'                  # 计时器事件，每隔1秒发送一次
event_type.EVENT_LOG = 'eLog'                      # 日志事件，全局通用

# Gateway相关
event_type.EVENT_TICK = 'eTick.'                   # TICK行情事件，可后接具体的vtSymbol
event_type.EVENT_TRADE = 'eTrade.'                 # 成交回报事件
event_type.EVENT_ORDER = 'eOrder.'                 # 报单回报事件
event_type.EVENT_POSITION = 'ePosition.'           # 持仓回报事件
event_type.EVENT_ACCOUNT = 'eAccount.'             # 账户回报事件
event_type.EVENT_CONTRACT = 'eContract.'           # 合约基础信息回报事件
event_type.EVENT_ERROR = 'eError.'                 # 错误回报事件

# CTA模块相关
event_type.EVENT_CTA_LOG = 'eCtaLog'               # CTA相关的日志事件
event_type.EVENT_CTA_STRATEGY = 'eCtaStrategy.'    # CTA策略状态变化事件

# 行情记录模块相关
event_type.EVENT_DATARECORDER_LOG = 'eDataRecorderLog' # 行情记录日志更新事件

# Wind接口相关
event_type.EVENT_WIND_CONNECTREQ = 'eWindConnectReq'   # Wind接口请求连接事件

sys.modules[__name__] = event_type
