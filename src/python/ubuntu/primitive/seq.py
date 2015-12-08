#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# seq コマンドは、数列を出力します。")
print(" bash> seq 3  # 3 までを出力する。")
subprocess.call("seq 3", shell=True)
print(" bash> seq -2 1  # -2 から 1 までを出力する。")
subprocess.call("seq -2 1", shell=True)
print(" bash> seq 0 10 20  # 0 から増分 10 で 20 までを出力する。")
subprocess.call("seq 0 10 20", shell=True)
print(' bash> seq -s ", " 10  # 項の間の --separator は ", " として 10 までを出力する。')
subprocess.call('seq -s ", " 10', shell=True)
print(' bash> seq -s ", " -w -10 10  # 各項の文字が占める幅を --equal-width として -10 から 10 までを出力する。')
subprocess.call('seq -s ", " -w -10 10', shell=True)
print(' bash> seq -s ", " 0 0.25 4.75  # 0 から増分 0.25 で 4.75 までを出力する。')
subprocess.call('seq -s ", " 0 0.25 4.75', shell=True)
print(" bash> seq -f '[%8.2f]' 3  # printf 形式の単精度浮動小数点数の整形を用いて 3  までを出力する。")
subprocess.call("seq -f '[%8.2f]' 3", shell=True)
print('# なお info seq によると、16 進数や 8 進数で出力したい場合には seq コマンド単独ではできないので printf コマンドなどと協調させることが勧められている。')

