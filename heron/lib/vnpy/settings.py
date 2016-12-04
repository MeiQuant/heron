# encoding: UTF-8
"""
配置文件
"""

import os
import json


def load_setting(key):

    file_name = 'settings.json'
    base_path = os.path.abspath(os.path.dirname(__file__))
    file_path = os.path.join(base_path, file_name)

    try:
        file_content = file(file_path)
        setting = json.load(file_content)
        value = setting[key]
    except:
        # todo 定义配置文件异常
        raise IOError

    return value

