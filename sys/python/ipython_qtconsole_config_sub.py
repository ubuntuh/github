'''
~/.ipython/profile_example/ipython_qtconsole_config.py

import os
path = os.environ['GIT']
import sys
sys.path.append(path + '/sys/python')
import ipython_qtconsole_config_sub as sub
sub.set_config(get_config)
'''

def set_config(get_config):
    c = get_config()
    c.IPythonQtConsoleApp.confirm_exit = False
    c.IPythonWidget.banner = ''
    c.IPythonWidget.height = 100
    c.IPythonWidget.width = 100
    c.InteractiveShellApp.exec_lines = [
        '%matplotlib inline',
        'from sympy import *',
        'from sympy.plotting import *',
        'from sympy.abc import *',
        'init_printing()',
        ]
