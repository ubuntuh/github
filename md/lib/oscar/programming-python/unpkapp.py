#!/usr/bin/python
import string
from apptools import StreamApp
from textpack import marker

class UnpackApp(StreamApp):
    def start(self):
        self.endargs()
    def run(self):
        mlen = len(marker)
        while 1:
            line = self.readline()
            if not line:
                break
            elif line[:mlen] != marker:
                self.write(line)
            else:
                name = string.strip(line[mlen:])
                self.message('creating: ' + name)
                self.setOutput(name)
if __name__ == '__main__': UnpackApp().main()

