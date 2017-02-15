import os

from MdApi import MdApi

class Adapter(MdApi):

    def __init__(self):
        
        super(Adapter, self).__init__()


    def connect(self):


        self.createFtdcMdApi(os.getcwd())

        self.registerFront('tcp://180.168.146.187:10010')


    def onFrontConnected(self):

        print 'front success'


if __name__ == '__main__':

    adapter = Adapter()
    adapter.connect()
