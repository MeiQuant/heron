# encoding: UTF-8

"""
Heron
----
程序主入口

* 启动之后自动连接CTP柜台

* 行情Server单独启一个线程

* 与客户端握手之后,推送tick数据

"""


import lib.vnTrader as vnTrader

# import pydevd

# pydevd.settrace('192.168.1.5', port=52727, stdoutToServer=True, stderrToServer=True)

def main():
    """主程序入口"""

    main_engine = vnTrader.vtEngine.MainEngine()
    main_engine.connect('CTP')

if __name__ == '__main__':
    main()


