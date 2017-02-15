# encoding: UTF-8
"""
均线策略
1. 实现策略
2. 载入策略
3. 启动heron
"""

from heron import Heron, Adapter, Trader, Market
from heron.strategy import ma


def main():

    app = Heron(__name__)
    # 注册要运行的组件
    Adapter().regsiter(app)

    # 向trader注册要运行的策略
    trader = Trader()
    ma().register(trader)

    trader.register(app)
    Market().register(app)

    app.run()

if __name__ == '__main__':
    main()
