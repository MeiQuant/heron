# encoding: UTF-8

"""
Heron
----
程序主入口

* 登录柜台

* 启动行情接受线程

* 启动socket.io服务端

"""


import sys
import heron.server as server


# import pydevd
# pydevd.settrace('192.168.1.5', port=52727, stdoutToServer=True, stderrToServer=True)


def main():
    """主程序入口"""
    reload(sys)
    sys.setdefaultencoding('utf-8')

    server.start()

if __name__ == '__main__':
    main()


