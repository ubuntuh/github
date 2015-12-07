#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import socket

print("# 環境変数についてテストします。")
print("# bash でアクセスできても bash で export されていない変数は、単なる shell variable であって environment variable （下位プロセスから参照可能）ではないので、Python の os.environ.get 関数で取得することはできないようです。set コマンドと env コマンドの出力を grep して比べると、export されていない変数は前者でのみ出力されることが確認できます。勝手な変数を bash で export すれば、Python で os.environ.get 関数で受け取れます。")
home = os.environ.get("HOME")
print("$HOME = " + home)
hostname = os.environ.get("HOSTNAME")
print("$HOSTNAME = " + str(hostname))
print("socket.gethostname() = " + socket.gethostname())
lang = os.environ.get("LANG")
print("$LANG = " + lang)
print("# 1 つ前のワーキングディレクトリは $OLDPWD (old print working directory) に入っています。")
oldpwd = os.environ.get("OLDPWD")
print("$OLDPWD = " + oldpwd)
print("# コマンドを自動的に検索させるディレクトリらは $PATH に入っています。")
path = os.environ.get("PATH")
print("$PATH = " + path)
print("# $PATH の内容を改行で整えると次のようになります。")
split = path.split(":")
joined = "\n".join(split)
print(joined)
ppid = os.environ.get("PPID")
print("$PPID = " + str(ppid))
print("os.getppid() = " + str(os.getppid()))
pwd = os.environ.get("PWD")
print("$PWD = " + pwd)
shell = os.environ.get("SHELL")
print("$SHELL = " + shell)
term = os.environ.get("TERM")
print("$TERM = " + term)
print("# $UID (user ID) にはユーザ ID が入っています。")
uid = os.environ.get("UID")
print("$UID = " + str(uid))
print("os.getuid() = " + str(os.getuid()))
print("# $USER には user name が入っています。")
user = os.environ.get("USER")
print("$USER = " + user)
