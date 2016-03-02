#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess

print("# head コマンドは、入力の最初の 10 行のみ出力します。")
print("\t$ seq 100 | head")
subprocess.call("seq 100 | head", shell=True)
print("# -n オプションを使うことで、出力する行数を指定できます。")
print("\t$ seq 100 | head -n 1")
subprocess.call("seq 100 | head -n 1", shell=True)
print("# パイプを使わずにも利用できます。")
print("\t$ head -n 5 head.py")
subprocess.call("head -n 5 head.py", shell=True)

