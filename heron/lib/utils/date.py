# encoding: UTF-8
"""
日期工具函数
"""

from datetime import datetime


def today():
    """获取当前本机电脑时间的日期"""
    return datetime.now().replace(hour=0, minute=0, second=0, microsecond=0)