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
    c.IPythonQtConsoleApp.confirm_exit = False
    c.IPythonWidget.banner = ''
    c.IPythonWidget.editor = 'gedit'
    c.IPythonWidget.height = 100
    c.IPythonWidget.width = 100
    c.IPythonWidget.buffer_size = 10000 # 過去の表示が保持される行数である。デフォルトは 500 である。
    c.InteractiveShellApp.exec_lines = [
        '%matplotlib inline',
        'from importlib import reload',
        'import dis',
        'import numpy as np',
        'import scipy as sp',
        'import matplotlib.pyplot as plt',
        'import networkx as nx',
        'from IPython.display import display',
        'import sympy as sy',
        'from sympy.abc import *', # sympy.abc は早々に import しなければならない。でなければ pi など多くの名前を覆ってしまうからである。
        'CCC, OOO, SSS, III, NNN, EEE, QQQ = sy.symbols("C O S I N E Q")', # 名前衝突を避けて定義する。
        'Alpha, Beta, Gamma, Delta, Epsilon, Zeta, Eta, Theta, Iota, Kappa, Lamda, Mu, Nu, Xi, Omicron, Pi, Rho, Sigma, Tau, Upsilon, Phi, CChi, Psi, Omega = sy.symbols("Alpha Beta Gamma Delta Epsilon Zeta Eta Theta Iota Kappa Lamda Mu Nu Xi Omicron Pi Rho Sigma Tau Upsilon Phi Chi Psi Omega")', # sympy.abc ではギリシャ文字大文字について定義されていないので定義する。lambda と chi については名前衝突を避けて定義する。
        'from sympy import *',
        'from sympy.combinatorics.permutations import *',
        'from sympy.plotting import *',
        'init_printing()',
        ]
