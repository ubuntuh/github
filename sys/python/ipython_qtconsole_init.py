#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
- IPython、特に現在は IPython Qt Console のための設定ファイルである。
- IPython については特定のコマンドで、例えば ipython3 profile create example として profile というものが作成できる。
- また、IPython の起動時に、ipython3 qtconsole --profile example などとすることで、利用する profile を指定できる。
- この時、設定ファイルとして、~/.ipython/profile_example/ipython_qtconsole_config.py といったファイルが読み込まれる。このファイルに設定を記述するのが、最も基本的な方法である。また、自動的に作成されるこのファイルには、コメントとして、様々な設定の例が説明されている。
- この、（ipython_qtconsole_config.py といった）設定ファイルでは、get_config という名前の関数が利用できる。
- ここで、呼び出し側がどのようにしてその名前を与えているのか、方法は知らない。
- c = get_config() などとし、c.IPythonWidget.banner = 'hello, world' などとすることで設定がカスタマイズできる。
- ただし、すでに関数 get_config は得られているので、任意に私的なスクリプトを import し、そこにある関数を呼び出して引数に get_config を与えることもできる。（あるいは、c.IPythonQtConsoleApp.extra_config_file を設定することがより正当な方法であるかもしれない。）
- もし、環境変数 PYTHONPATH にサーチパスが追加されているならば、import で直ちに私的なスクリプトを import できる。（あるいは他の方法も考えられるかもしれない。）
- c.InteractiveShellApp.exec_lines = ['%matplotlib inline', ...] などとして、IPython が起動した時に毎回自動的に行ってほしい処理を記述できる。
- またここで、私的な任意のスクリプトを import することで、起動時の初期化ができる。IPython を起動した瞬間からいくらかの名前が使えると便利である。
- このように、2 段階に設定ファイルを呼び出すことで、設定情報のほとんどを例えば同期された共有空間に設置できる。
- そして、このファイルはその 2 段階目であることが意図されている。
'''

import importlib
def import_(from_, as_=None, names=[], star=False):
    """与えられた名前のモジュールをインポートする関数である。失敗した場合、エラーを出力する。この関数を使うと、普通に import する場合に比べていくらか煩雑になる。IPython の設定ファイルが普通にロードされると、import などで、そのマシンにインストールされていないパッケージがあると、エラーになって読み込みは終了してしまうようであり、なおかつエラーメッセージが出力されないようである。そこで、この関数の目的は、読み込めないモジュールを無視して設定を続行することと、読み込めなかった場合にその旨、出力することである。より良い方法があるかもしれないが、これはとりあえず動作しているようである。"""
    try:
        module = importlib.import_module(from_)
    except ImportError:
        print('Failed to import ' + from_ + '.')
        return
    if star:
        my_module = module
        # http://stackoverflow.com/questions/21221358/python-how-to-import-all-methods-and-attributes-from-a-module-dynamically
        module_dict = my_module.__dict__
        try:
            to_import = my_module.__all__
        except AttributeError:
            to_import = [name for name in module_dict if not name.startswith('_')]
        globals().update({name: module_dict[name] for name in to_import})
        return
    if names:
        for name in names:
            globals()[name] = module.__dict__[name]
        return
    if as_ is None:
        as_ = from_
    globals()[as_] = module

import_('example')
import_('time')
startTime = time.time()
import_('importlib', names=['reload'])
import_('csv')
import_('dis')
import_('json')
import_('os')
import_('subprocess')

import_('numpy', as_='np')
import_('scipy', as_='sp')
import_('matplotlib.pyplot', as_='plt')
import_('networkx', as_='nx')
import_('pandas', as_='pd')
import_('IPython.display', names=['display'])
import_('IPython.core.magic', star=True)

# from /usr/lib/python3/dist-packages/sympy/__init__.py
# 以下の 3 つはデフォルトでは、読み込みが遅いとしてインポートされていないが、ここではする。
import_('sympy.combinatorics', star=True)
import_('sympy.physics',  names=['units'])
import_('sympy.abc', star=True) # sympy.abc は早々に import しなければならない。でなければ pi など多くの名前を覆ってしまうからである。
# 以下は上記のファイルからインポートされているので、from sympy import * をするならばインポートする必要がないが、参考のために再掲する。
from sympy.core import *
from sympy.logic import *
from sympy.assumptions import *
from sympy.polys import *
from sympy.series import *
from sympy.functions import *
from sympy.ntheory import *
from sympy.concrete import *
from sympy.simplify import *
from sympy.sets import *
from sympy.solvers import *
from sympy.matrices import *
from sympy.geometry import *
from sympy.utilities import *
from sympy.integrals import *
from sympy.tensor import *
from sympy.parsing import *
from sympy.calculus import *
from sympy.plotting import plot, textplot, plot_backends, plot_implicit
from sympy.printing import pretty, pretty_print, pprint, pprint_use_unicode, \
    pprint_try_use_unicode, print_gtk, print_tree, pager_print, TableForm
from sympy.printing import ccode, fcode, jscode, mathematica_code, octave_code, \
    latex, preview
from sympy.printing import python, print_python, srepr, sstr, sstrrepr
from sympy.interactive import init_session, init_printing

from sympy.printing.dot import dotprint
import_('sympy', star=True)
import_('sympy', as_='sy') # すでに名前空間をインポートしているが sy としてもインポートしておく。

CCC, OOO, SSS, III, NNN, EEE, QQQ = sy.symbols('C O S I N E Q') # 名前衝突を避けて定義する。
Alpha, Beta, Gamma, Delta, Epsilon, Zeta, Eta, Theta, Iota, Kappa, Lamda, Mu, Nu, Xi, Omicron, Pi, Rho, Sigma, Tau, Upsilon, Phi, CChi, Psi, Omega = sy.symbols('Alpha Beta Gamma Delta Epsilon Zeta Eta Theta Iota Kappa Lamda Mu Nu Xi Omicron Pi Rho Sigma Tau Upsilon Phi Chi Psi Omega') # sympy.abc ではギリシャ文字大文字について定義されていないので定義する。lambda と chi については名前衝突を避けて定義する。

def ploteq(*args, **kwargs):
    """軸のアスペクト比を均等にプロットするための関数である。broken。以下の方法で均等なプロットを見ることはできるが、Plot._backend を生成するためには plot(..., show=False) とはできないようである。なので均等ではないプロットと均等なプロットとが両方表示されてしまう。しかし何にせよ、均等なプロットを見ることはできている。それらが両方表示されるのは好ましいと考えることもできる。"""
    p = plot(*args, **kwargs)
    p._backend.ax.set_aspect('equal')
    return p._backend.fig

def plot_implicit_equal(*args, **kwargs):
    p = plot_implicit(*args, **kwargs)
    p._backend.ax.set_aspect('equal')
    return p._backend.fig

@magics_class
class Magics0(Magics):
    @line_magic
    def ej(self, line):
        command = 'grep --color=always "' + line + '" ' + os.environ['ejdic']
        process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE)
        stdout_data, _ = process.communicate()
        print(stdout_data.decode('utf-8'))
    @line_magic
    def je(self, line):
        command = 'grep --color=always "' + line + '" ' + os.environ['edict']
        process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE)
        stdout_data, _ = process.communicate()
        print(stdout_data.decode('utf-8'))
    @line_magic
    def gg(self, line):
        command = 'xdg-open "https://www.google.co.jp/search?q=' + line + '"'
        subprocess.call(command, shell=True)
    @line_magic
    def ge(self, line):
        command = 'xdg-open "https://www.google.co.jp/search?gl=US&hl=en&q=' + line + '"'
        subprocess.call(command, shell=True)
    @line_magic
    def gj(self, line):
        command = 'xdg-open "https://www.google.co.jp/search?gl=JP&hl=ja&q=' + line + '"'
        subprocess.call(command, shell=True)
ip = get_ipython()
ip.register_magics(Magics0)

now = time.time()
print('System configured. (in {0:.3f} s)'.format(now - startTime))
del now
