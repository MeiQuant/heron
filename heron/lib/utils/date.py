# encoding: UTF-8
"""
日期工具函数
"""

from datetime import date, datetime


def today():
    """获取当前本机电脑时间的日期"""
    return date.today().isoformat()


def now():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")