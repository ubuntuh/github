#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# uptime コマンドを使うと、OS が動いている時間を知ることができます。")
print(" bash> uptime")
subprocess.call("uptime", shell=True)
print("# これはそれぞれ、現在時刻、起動してからの経過時間、何人のユーザが現在ログインしているか、過去 1 分間、5 分間、15 分間のシステムのロードアベレージです。")
print("# uptime を --pretty な見やすい形で見ることもできます。")
print(" bash> uptime -p")
subprocess.call("uptime -p", shell=True)
print("# 起動時刻そのもの (system up --since) を得ることもできます。")
print(" bash> uptime -s")
subprocess.call("uptime -s", shell=True)

