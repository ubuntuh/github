#!/usr/bin/env python
# -*- coding: utf-8 -*-
import subprocess

print("# x86info というコマンドがあります。")
print(" bash> x86info --all | head")
subprocess.call("x86info --all | head", shell=True)
