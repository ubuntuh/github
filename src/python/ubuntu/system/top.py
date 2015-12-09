#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# top コマンドを使うと、現在動いているプロセスらの情報をリアルタイムに見ることができます。")
print("# またコマンドは、リアルタイムに画面を更新するコマンドの代表例の一つでもあります。")

# http://stackoverflow.com/questions/27808499/python-popen-empty-stdout-with-top
popen = subprocess.Popen("top -c -b -n 1 | head", stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
output, error = popen.communicate()
sys.stdout.write(output)

