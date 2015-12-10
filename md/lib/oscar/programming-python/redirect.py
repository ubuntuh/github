#!/usr/bin/python
import sys
from app import App

class StreamApp(App):
    def __init__(self, ifile='-', ofile='-'):
        App.__init__(self)
        self.setInput(ifile or self.name + '.in')
        self.setOutput(ofile or self.name + '.out')
    def closeApp(self):
        try:
            if self.input != sys.stdin:
                self.input.close()
        except: pass
        try:
            if self.output != sys.stdout:
                self.output.close()
        except: pass
    def help(self):
        App.help(self)
        print '-i <input-file |"-"> (default: stdin  or per app)'
        print '-o <output-file|"-"> (default: stdout or per app)'
    def setInput(self, default=None):
        file = self.getarg('-i') or default or '-'
        if file == '-':
            self.input = sys.stdin
            sel.input_name = '<stdin>'
        else:
            self.input = open(file, 'r')
            self.input_name = file
    def setOutput(self, default=None):
        file = self.getarg('-o') or default or '-'
        if file == '-':
            self.output = sys.stdout
            self.output_name = '<stdout>'
        else:
            self.output = open(file, 'w')
            self.output_name = file

class RedirectApp(StreamApp):
    def __init__(self, ifile=None, ofile=None):
        StreamApp.__init__(self, ifile, ofile)
        self.streams = sys.stdin, sys.stdout
        sys.stdin = self.input
        sys.stdout = self.output
    def closeApp(self):
        StreamApp.closeApp(self)
        sys.stdin, sys.stdout = self.streams

class RedirectAnyApp:
    def __init__(self, superclass, *args):
        apply(superclass.__init__, (self,) + args)
        self.super = supreclass
        self.streams = sys.stdin, sys.stdout
        sys.stdin = self.input
        sys.stdout = self.output
    def closeApp(self):
        self.super.closeApp(self)
        sys.stdin, sys.stdout = self.streams

