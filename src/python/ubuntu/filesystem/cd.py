#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# cd コマンドについてテストします。cd コマンドは bash の組み込み命令であって、システムに同名のプログラムは存在しません。")
print("# cd は change directory の意味であり、カレントディレクトリ（ワーキングディレクトリ）を変更します。")
print("# cd コマンドを使うと、bash の shell variable である OLDPWD (old print working directory) に直前のカレントディレクトリの絶対パスが代入されます。cd - と入力すると、OLDPWD が表すディレクトリに移動します。なお cd - を使うと新しいワーキングディレクトリのパスが出力されます。")

commands = '''
echo '$PWD =' $PWD
echo '$OLDPWD =' $OLDPWD
echo 'Executing cd -'
cd - > /dev/null
echo '$PWD =' $PWD
echo '$OLDPWD =' $OLDPWD
echo 'Executing cd -'
cd - > /dev/null
echo '$PWD =' $PWD
echo '$OLDPWD =' $OLDPWD
'''
subprocess.call(commands, shell=True)

