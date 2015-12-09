#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# ps コマンドを利用することで、プロセスらについての情報を得ることができます。")
print("# 何もオプションを与えずに実行すると、ログイン中のユーザアカウントが使用しているプロセスらについてのみの情報が表示されます。")
print(" bash> ps")
subprocess.call("ps", shell=True)
print("# それぞれのプロセスについてもう少し詳しい情報を得ることもできます。")
print(" bash> ps l")
subprocess.call("ps l", shell=True)
print("# F は process flags です。1 は、そのフォークされたものの実行はされていないことを意味します。なおフォークとは、自らのコピーとして新たなプロセスを生成することです。4 は、スーパーユーザ権限が使われたことを意味します。process flags は、1 か 4 のみなので、結果としての値は、0 か 1 か 4 か 5 の 4 種類しかありません。")
print("# UID (user ID) は、プロセスの owner であるユーザのユーザ ID です。")
print("# PID (process ID) は、プロセス ID です。")
print("# PPID (parent process ID) は、親プロセスのプロセス ID です。")
print("# PRI (priority) は、そのプロセスの優先度を表します。値が小さいほど優先されます。")
print("# NI (nice) は、nice 値です。nice 値もプロセスの優先度を意味します。高いほど他のプロセスにとって nice であり、つまり優先度は低いです。")
print("# VSZ (virtual memory size) は、仮想メモリのサイズです。単位は KiB (kibibyte) です。")
print("# RSS (resident set size) は、使用した物理メモリのサイズです。単位は kilobyte です。")
print("# WCHAN (waiting channel) は、プロセスが今スリープしているカーネル関数の名前です。プロセスが動作中の場合には -、プロセスがマルチスレッドになっている上にこの ps がスレッドを表示しない設定で実行されている場合には * と表示されます。")
print("# STAT (state) は、process state codes によってプロセスの状態を表します。D は割り込み不可能なスリープ状態、R は実行中ないし実行待ち、S は割り込み可能なスリープ状態、T はストップされている状態、W はページングされている状態、X は dead、Z は、終了されたが処分されていないゾンビプロセスです。また、< は高い優先度、N (nice) は低い優先度、L はメモリにロックされたページを持っていること、s はセッションのリーダー、l はマルチスレッド、+ はフォアグラウンド（前景）のプロセスグループに属していることを意味します。")
print("# TTY (teletype) は、繋がっているターミナルを表します。例えば pts/1 と表示されているなら、echo msg > /dev/pts/1 で文字列が出力されるようなターミナルに接続されています。")
print("# TIME は、そのプロセスによって使われた CPU 時間の累積値を表示します。")
print("# COMMAND は、プログラムのファイル名です。")
print("# 任意の属性についてのみ出力することもできます。")
print(" bash> ps -o pid,command")
subprocess.call("ps -o pid,command", shell=True)

