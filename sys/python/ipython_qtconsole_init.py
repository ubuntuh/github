#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from sympy.printing.dot import dotprint
from sympy import *
from sympy.plotting import *

def ploteq(*args, **kwargs):
    """軸のアスペクト比を均等にプロットするための関数である。broken。以下の方法で均等なプロットを見ることはできるが、Plot._backend を生成するためには plot(..., show=False) とはできないようである。なので均等ではないプロットと均等なプロットとが両方表示されてしまう。しかし何にせよ、均等なプロットを見ることはできている。それらが両方表示されるのは好ましいと考えることもできる。"""
    p = plot(*args, **kwargs)
    p._backend.ax.set_aspect('equal')
    return p._backend.fig

def plot_implicit_equal(*args, **kwargs):
    p = plot_implicit(*args, **kwargs)
    p._backend.ax.set_aspect('equal')
    return p._backend.fig

