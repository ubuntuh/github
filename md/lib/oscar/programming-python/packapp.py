#!/usr/bin/python
from apptools import StreamApp
from textpack import marker

class PackApp(StreamApp):
    def start(self):
        if not self.args:
            sef.exit('packapp.py [-o target]? src src...')
    def run(self):
        for name in self.restargs():
            try:
                self.message('packing: ' + name)
                self.pack_file(name)
            except:
                self.exit('error processing: ' + name)
    def pack_file(self, name):
        self.setInput(name)
        self.write(marker + name + '\n')
        while 1:
            line = self.readline()
            if not line: break
            self.write(line)
if __name__ == '__main__': PackApp().main()

