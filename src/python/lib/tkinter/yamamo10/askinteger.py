#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.simpledialog as sd
# import math
class MainWindow(tk.Frame):
    def __init__(self, parent):
        super(MainWindow, self).__init__(parent)
        parent.title("Fibonacci number")
        parent.minsize(200, 50)
        self.label = tk.Label(parent, text="Fibonacci")
        self.label.pack()
        self.buttons = tk.Button(parent, text="Integer", fg="red", command=self.askint)
        self.buttons.pack()
    def fibonacci(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        return self.fibonacci(n - 2) + self.fibonacci(n - 1)
    def set(self, st):
        self.label.config(text=st)
    def askint(self):
        n = sd.askinteger("Input integer", "Fibonaci n")
        fn = self.fibonacci(n)
        self.set(fn)
if __name__ == "__main__":
    root = tk.Tk()
    mw = MainWindow(root)
    root.mainloop()
