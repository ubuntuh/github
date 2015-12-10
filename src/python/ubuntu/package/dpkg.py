#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# dpkg (Debian package) コマンドを使うと、パッケージについての操作ができます。")
print("# which コマンドを使うとコマンドの絶対パスがわかります。")
print(" bash> which ls")
subprocess.call("which ls", shell=True)
print("# dpkg コマンドの -S (--search~) オプションを使うと、インストール済みのパッケージの中から与えられたファイル名を検索します。言い換えると、ファイルがわかっていれば、そのファイルが含まれるパッケージの名前がわかります。")
print(" bash> dpkg -S /bin/ls")
subprocess.call("dpkg -S /bin/ls", shell=True)
print("# 例えば coreutils パッケージに含まれるコマンドだとわかったならば、そのソースコードが欲しい場合、apt-get source coreutils とすれば、パッケージ全体のソースコードを得ることができます。sudo とする必要はありません。カレントディレクトリにダウンロードされます。この方法で必ずソースコードが得られるというわけではないようです。")

