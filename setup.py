# encoding: UTF-8
"""

"""
from setuptools import setup, find_packages

setup(
    name='Heron',
    version='0.0.1',
    long_description=__doc__,
    packages=find_packages(include=['heron', 'heron.*']),
    include_package_data=True,
    zip_safe=False,
    install_requires=[
        'Flask',
        'flask-socketio',
        'eventlet',
        'python-engineio',
        'python-socketio',
        'pymongo',
        'redis',
        'nose'
    ],
    author='MeiQuant',
    url='https://github.com/MeiQuant/Heron'
)