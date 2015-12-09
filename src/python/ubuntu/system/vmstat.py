#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# vmstat (virtual memory statistics) コマンドを使うと、仮想メモリの情報を見られます。")
subprocess.call("vmstat", shell=True)

