#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# kill コマンドを使うと、任意のプロセスを終了することができます。")
print("kill は、bash の組み込みコマンドとしても存在しています。")
print(" bash> type kill")
subprocess.call("type kill", shell=True)
print(" bash> which kill")
subprocess.call("which kill", shell=True)
print("# kill コマンドで使えるシグナルの一覧を見ます。")
print(" bash> kill -l")
print("...なぜか表示が崩れるので表示しません。")
print(" bash> /bin/kill -l")
subprocess.call("/bin/kill -l", shell=True)
print("# システムの kill コマンドには、-L というオプションがあります。特に必要ありませんが、別のプログラムだということが確認できます。")
print(" bash> /bin/kill -L")
subprocess.call("/bin/kill -L", shell=True)
