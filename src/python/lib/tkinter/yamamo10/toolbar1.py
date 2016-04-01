#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import tkinter as tk
def callback():
    print("callback the callback!")
if __name__ == "__main__":
    root = tk.Tk()
    toolbar = tk.Frame(root)
    b = tk.Button(toolbar, text="new", width=6, command=callback)
    b.pack(side="left", padx=2, pady=2)
    b = tk.Button(toolbar, text="open", width=6, command=callback)
    b.pack(side="left", padx=2, pady=2)
    toolbar.pack(side="top", fill=tk.X)
    root.mainloop()
