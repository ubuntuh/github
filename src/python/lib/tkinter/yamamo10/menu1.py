#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
def callback():
    print("called the callback!")
if __name__ == "__main__":
    root = tk.Tk()
    menu = tk.Menu(root)
    root.config(menu=menu)
    filemenu = tk.Menu(menu)
    menu.add_cascade(label="File", menu=filemenu)
    filemenu.add_command(label="New", command=callback)
    filemenu.add_command(label="Open...", command=callback)
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=callback)
    helpmenu = tk.Menu(menu)
    menu.add_cascade(label="Help", menu=helpmenu)
    helpmenu.add_command(label="About...", command=callback)
    root.mainloop()
