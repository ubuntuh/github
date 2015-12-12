#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# shuf (shuffle) コマンドは、入力をシャッフルするコマンドです。")
print(" bash> seq 6 | shuf")
subprocess.call("seq 6 | shuf", shell=True)
print("# 次のようにして、乱数を得るのにも使えます。")
print("# ここでは、同じ値を --repeat することを許し、--input-range は 1 から 6 までとして、出力する値の数は -n 6 個と指定しています。")
print(" bash> shuf -r -i 1-6 -n 6")
subprocess.call("shuf -r -i 1-6 -n 6", shell=True)

