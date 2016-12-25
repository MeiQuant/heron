# encoding: UTF-8
"""
App etc
"""

from env import ENV

from heron.core.exceptions import HeronSettingsError

import base
import prod
import dev
import test


class SettingsDict(dict):
    """
    readonly dict
    """
    def __init__(self, *args, **kwargs):
        self.update(*args, **kwargs)

    def __setitem__(self, key, value):
        """ x.__setitem__(key, value) <==> x[key]=y """
        if self.__contains__(key):
            raise HeronSettingsError
        pass


_settings = {
    'production': SettingsDict(base.settings, **prod.settings),
    'development': SettingsDict(base.settings, **dev.settings),
    'testing': SettingsDict(base.settings, **test.settings)
}

if ENV in _settings:
    settings = _settings[ENV]
else:
    settings = _settings['production']
    raise EnvironmentError
