#!/usr/bin/python
import sys, string
from app import App

class InternalApp(App):
    def __init__(self, text=''):
        App.__init__(self)
        self.input = Input(text)
        self.output = Output()
        self.input_name = '<internal>'
        self.output_name = '<internal>'
    def stop(self):
        App.stop(self)
        return self.output.text

class RedirectInternalApp(InternalApp):
    def __init__(self, input=''):
        InternalApp.__init__(self, input)
        self.streams = sys.stdin, sys.stdout
        sys.stdin = self.input
        sys.stdout = self.output
    def closeApp(self):
        sys.stdin, sys.stdout = self.streams

class FakeStream:
    def close(self):
        pass
    def flush(self):
        pass
    def isatty(self):
        return 0

class Input(FakeStream):
    def __init__(self, input):
        self.text = input
    def read(self, *size):
        if not size:
            res, self.text = self.text, ''
        else:
            res, self.text = self.text[: size[0]], self.text[size[0] :]
        return res
    def readline(self):
        eoln = string.find(self.text, '\n')
        if eoln == -1:
            res, self.text = self.text, ''
        else:
            res, self.text = self.text[: eoln + 1], self.text[eoln + 1 :]
        return res
    def readlines(self):
        res = []
        while 1:
            line = self.readline()
            if not line: break
            res.append(line)
        return res

class Output(FakeStream):
    def __init__(self):
        self.text = ''
    def write(self, string):
        self.text = self.text + string
    def writelines(self, lines):
        for line in lines: self.write(line)

