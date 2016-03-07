#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess

print("# date コマンドは、現在時刻を出力します。")
print("\t$ date")
subprocess.call("date", shell=True)
print("# -u オプション（または --utc オプション）を使うと、世界標準時を得ることができます。")
print("\t$ date -u")
subprocess.call("date -u", shell=True)

