# encoding: UTF-8
#!/usr/bin/env python
"""
安装CTP行情交易接口的Option版
"""
import platform, os
from distutils.core import setup, Extension


pwd = os.getcwd()

optional = {}
if platform.system() == 'Linux':
    optional['extra_compile_args'] = ['-std=c++11']
    # 这里最好使用绝对路径
    optional['runtime_library_dirs'] = [pwd + '/api/linux64']
    optional['include_dirs'] = [pwd + '/api/linux64', '/usr/include/boost']
    optional['library_dirs'] = [pwd + '/api/linux64']
if platform.system() == 'Windows':
    optional['include_dirs'] = ['./api/win32']
    optional['library_dirs'] = ['./api/win32']
    if '64 bit' in platform.python_compiler():
        optional['include_dirs'] = ['./api/win64']
        optional['library_dirs'] = ['./api/win64']

argments_md = dict(name='MdApi',
                sources=[pwd + '/MdApi.cpp'],
                language='c++',
                libraries=['boost_python', 'boost_thread', 'thostmduserapi'],
                depends=[pwd + '/MdApi.h'])
argments_md.update(optional)

argments_td = dict(name='TdApi',
                   sources=[pwd + '/TdApi.cpp'],
                   language='c++',
                   libraries=['boost_python', 'boost_thread', 'thosttraderapi'],
                   depends=[pwd + '/TdApi.h'])
argments_td.update(optional)

setup(name='heron_api',
      version='0.0.1',
      description='CTP for Python',
      long_description='CTP for Python',
      author='MeiQuant',
      author_email='xiuguozhao@gmail.com',
      url='https://github.com/MeiQuant/heron-api',
      keywords=['ctp','futures','stock'],
      license='LGPL-3.0',
      platforms=['linux-x86_64','win32','win-amd64'],
      ext_modules=[Extension(**argments_md), Extension(**argments_td)]
      )