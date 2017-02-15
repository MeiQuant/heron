# encoding: UTF-8
"""
订单组件，提供下单、撤单等功能
结合Router使用
"""

from heron import Component


class Order(Component):

    def __init__(self):
        super(Order, self).__init()

    @property
    def router(self):
        return self.router

    @router.setter
    def router(self, router):
        self.router = router

    def send(self):
        """
        订单发送
        :return:
        """
        pass
