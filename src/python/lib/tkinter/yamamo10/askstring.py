#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.simpledialog as sd
class MainWindow(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self, master)
        self.label = tk.Label(master, text="There is no data.")
        self.label.pack()
        self.button = tk.Button(master, text="Input String", fg="red", command=self.askstr)
        self.button.pack(side="left")
    def set(self, str):
        self.label.config(text=str)
    def askstr(self):
        data = sd.askstring("test askstring", "input", initialvalue="hoge")
        self.set(data)
if __name__ == "__main__":
    root = tk.Tk()
    mw = MainWindow(root)
    root.mainloop()
