#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# pstree というコマンドがあります。動いているプロセスを木構造で表示します。")
print("# 子スレッドの名前は波括弧に囲まれて表示されます。")
print(" bash> pstree | head")
subprocess.call("pstree | head", shell=True)
