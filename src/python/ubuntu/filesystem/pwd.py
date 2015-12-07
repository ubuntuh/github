#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# pwd コマンドについてテストします。")
print("# pwd は print working directory の意味で、ワーキングディレクトリ = カレントディレクトリのパスを出力します。")
popen = subprocess.Popen(["pwd"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output, error = popen.communicate()
sys.stdout.write(output)
print("# pwd コマンドは Linux のものと、bash の組み込みのものがあります。それぞれの解説は、man pwd あるいは help pwd とすることでそれぞれ閲覧できます。bash の組み込みの pwd には --version オプションはないようです。")
print("# Python における subprocess.Popen の利用において、shell=True とすると bash 組み込みの pwd が呼び出され、そうでないと システムの pwd が呼び出されるようです。組み込みかどうかは type pwd とすればわかります。システムの pwd の位置は which pwd とすればわかるので、絶対パスで参照すれば bash 上からでもシステムの pwd を呼び出せます。")
popen = subprocess.Popen(["pwd", "--version"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
output, error = popen.communicate()
sys.stdout.write(output)

