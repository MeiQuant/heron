# encoding: UTF-8
"""

"""

import unittest

from heron.etc import settings, SettingsDict
from heron.core.exceptions import HeronSettingsError


class TestSettings(unittest.TestCase):

    def test_settings_dict(self):

        test_dict = SettingsDict()

        test_dict['a'] = 'a'

    def test_settings_error(self):
        with self.assertRaises(HeronSettingsError):
            settings['env'] = 'aaa'

    def test_settings_get(self):
        # env
        self.assertEqual(settings['env'], 'development')


if __name__ == '__main__':
    unittest.main()
