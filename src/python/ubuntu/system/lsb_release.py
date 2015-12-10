#!/usr/bin/python
# -*- coding: utf-8 -*-
import subprocess

print(" bash>lsb_release -a")
subprocess.call("lsb_release -a", shell=True)
print(" bash>cat /etc/lsb-release")
subprocess.call("cat /etc/lsb-release", shell=True)
