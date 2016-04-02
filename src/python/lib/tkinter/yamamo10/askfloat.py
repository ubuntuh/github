#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.simpledialog as sd
import math
class MainWindow(tk.Frame):
    def __init__(self, parent):
        super(MainWindow, self).__init__(parent)
        self.label = tk.Label(parent, text="Trigonometric function.")
        self.label.pack()
        self.buttons = tk.Button(parent, text="sin(x)", fg="red", command=lambda: self.askstr("sin"))
        self.buttons.pack(side="left")
        self.buttonc = tk.Button(parent, text="cos(x)", fg="red", command=lambda: self.askstr("cos"))
        self.buttonc.pack(side="left")
    def set(self, st):
        self.label.config(text=st)
    def askstr(self, f):
        theta = sd.askfloat("test askinteger", "deg")
        if f == "sin":
            data = str(math.sin(math.radians(theta)))
        if f == "cos":
            data = str(math.cos(math.radians(theta)))
        self.set(data)
if __name__ == "__main__":
    root = tk.Tk()
    mw = MainWindow(root)
    root.mainloop()
