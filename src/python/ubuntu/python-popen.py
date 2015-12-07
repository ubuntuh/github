#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess
import sys

print("# Python においてサブプロセスを実行する方法の基礎についてテストします。")
print("# Python で文字列を出力するには print 関数を使います。デフォルトで標準出力 sys.stdout から出力されます。自動的に改行が付加されます。")
print(" python> print(\"hello, world\")");
print("hello, world")
print("# Python で外部コマンドを利用するには、import subprocess として subprocess パッケージを参照できるようにした上で、subprocess.call 関数を使います。例えば、現在時刻を出力する date コマンドを次のように実行できます。")
print(" python> subprocess.call(\"date\")")
subprocess.call("date")
print("# 引数を与えることもできます。date コマンドの出力を ISO 8601 形式にする引数 -I を使ってみましょう。")
print(" python > subprocess.call([\"date\", \"-I\"])")
subprocess.call(["date", "-I"])
print("# なお、subprocess.call(\"date -I\") とすると、「date -I」というファイルは存在しないためエラーになります。")
print("# 一方、コマンドの出力を得たい場合には、Popen オブジェクトを作成して次のようにする必要があります。")
print(" python> popen = subprocess.Popen(\"date\", stdout=subprocess.PIPE)")
print(" python> output, error = popen.communicate()")
print(" python> print(\"Date = \" + output)")
popen = subprocess.Popen("date", stdout=subprocess.PIPE)
output, error = popen.communicate()
sys.stdout.write("Date = " + output)
print("# コマンドに引数を渡したい場合には上の call 関数を使った場合と同様に、[\"date\", \"-I\"] などとする必要があり、もし \"date -I\" を渡すとエラーになります。");
print(" python> popen = subprocess.Popen([\"date\", \"-I\"], ...)")
popen = subprocess.Popen(["date", "-I"], stdout=subprocess.PIPE)
output, error = popen.communicate()
sys.stdout.write("Date = " + output)
print("# Popen の引数で shell=True とすれば \"date -I\" を渡しても大丈夫なようです。また逆に、shell=True としたならば、[\"date\", \"-I\"] などと渡しても引数が無視されてしまうようです。")
popen = subprocess.Popen("date -I", stdout=subprocess.PIPE, shell=True)
output, error = popen.communicate()
sys.stdout.write("Date = " + output)
print("# コマンドに入力を与えたい場合には、Popen オブジェクトの communicate 関数を呼び出す際に引数として与えます。")
print(" python> popen = subprocess.Popen(\"grep line2\", stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)")
print(" python> output, error = popen.communicate(\"line1\\nline2\\nline3\")")
print(" python> sys.stdout.write(output)")
popen = subprocess.Popen("grep line2", stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
output, error = popen.communicate("line1\nline2\nline3")
sys.stdout.write(output)

