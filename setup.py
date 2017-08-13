# encoding: UTF-8
"""

"""

from setuptools import setup, find_packages, Extension

ext_data = dict(

)

extensions = []

for name, data in ext_data.items():

    obj = Extension('pandas.%s' % name,
                    sources=sources,
                    depends=data.get('depends', []),
                    include_dirs=include,
                    extra_compile_args=extra_compile_args)

    extensions.append(obj)


setup(
    name='heron',
    version='0.0.1a',
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