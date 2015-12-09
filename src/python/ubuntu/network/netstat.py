#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print("# netstat (network statistics) コマンドを使うと、ネットワーク接続についての情報を得ることができます。")
subprocess.call("netstat | head", shell=True)

