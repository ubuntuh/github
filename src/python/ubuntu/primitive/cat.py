#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess

print("# cat コマンドは、与えられたファイルの内容を連結して出力します。")
print("# 単に、1 つのファイルの内容を標準出力で見るためにも使えます。")
print("\t$ cat cat.py | head -n 5")
subprocess.call("cat cat.py | head -n 5", shell=True)
print("# cat <<EOF >example.txt などとすると、簡易的に複数行の新しいファイルを書くことができます。（なお、複数行でないなら、echo \"hello, world\" >example.txt などとすることも簡単です。）")

