#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
ipython3 profile create example

~/.ipython/profile_example/ipython_qtconsole_config.py

上のようなファイルに下のような記述を追加してこのスクリプトを用いることができる。

import os
path = os.environ['GIT']
import sys
sys.path.append(path + '/sys/python')
import ipython_qtconsole_config_sub as sub
sub.set_config(get_config)

あるいはシェルで PYTHONPATH が設定されている場合には単に次のようにする。

import ipython_qtconsole_config_sub as sub
sub.set_config(get_config)

%matplotlib inline として、デフォルトでは IPython のウィンドウ内に図を表示する設定にしてある。これを一時的に変更するためには、%matplotlib qt などとすればいい。

SymPy で、インタラクティブに数式を入力すると Latex で表示される。長い式はウィンドウからはみ出てしまい表示できないようである。pprint(expr) とすると unicode 形式で表示でき、line wrap される。また print(expr) とすると unicode すら使わずに表示できる。スクリプトファイルから Latex で出力するには、from IPython.display import display として display(expr) とすればいい。
'''

def set_config(get_config):
    c = get_config()
    c.IPythonQtConsoleApp.confirm_exit = False # 終了操作について確認を求めない。
    c.IPythonWidget.banner = '' # 起動時のメッセージを表示しない。
    c.IPythonWidget.editor = 'gedit' # デフォルトのテキストエディタを設定する。
    c.IPythonWidget.height = 100
    c.IPythonWidget.width = 100
    c.IPythonWidget.buffer_size = 10000 # 過去の表示が保持される行数である。デフォルトは 500 である。
    c.InteractiveShellApp.exec_lines = [
        '%matplotlib inline',
        'from ipython_qtconsole_init import *',
        'init_printing()',
        ]
