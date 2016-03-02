#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# find コマンドについてテストします。")
print("# find コマンドを使うと、与えた名前のファイルを検索できます。")
print("    $ find . -name *.py");
popen = subprocess.Popen(["find", ".", "-name", "*.py"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output, error = popen.communicate()
sys.stdout.write(output)

