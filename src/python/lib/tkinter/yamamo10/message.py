#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.messagebox as mb
filename = "hoge"
try:
    fp = open(filename)
except:
    mb.showwarning("Open file", "Cannnot open this file\n(%s)" % filename)
