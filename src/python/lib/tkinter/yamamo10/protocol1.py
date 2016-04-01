#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.messagebox as mb
def callback():
    if mb.askokcancel("Quit", "Do you really wish to quit?"):
        root.destroy()
if __name__ == "__main__":
    root = tk.Tk()
    root.protocol("WM_DELETE_WINDOW", callback)
    root.mainloop()
