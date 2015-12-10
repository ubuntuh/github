#!/usr/bin/python
import sys, os, traceback

AppError = 'App class error'

class App:
    def __init__(self, name=None):
        self.name = name or self.__class__.__name__
        self.args = sys.argv[1:]
        self.env = os.environ
        self.verbose = self.getopt('-v') or self.getenv('VERBOSE')
        self.input = sys.stdin
        self.output = sys.stdout
        self.error = sys.stderr
    def closeApp(self):
        pass
    def help(self):
        print self.name, 'command-line arguments:'
        print '-v (verbose)'
    def getopt(self, tag):
        try:
            self.args.remove(tag)
            return 1
        except:
            return 0
    def getarg(self, tag, default=None):
        try:
            pos = self.args.index(tag)
            val = self.args[pos + 1]
            self.args[pos : pos + 2] = []
            return val
        except:
            return default
    def getenv(self, name, default=''):
        try:
            return self.env[name]
        except KeyError:
            return default
    def endargs(self):
        if self.args:
            self.message('extra arguments ignored: ' + `self.args`)
            self.args = []
    def restargs(self):
        res, self.args = self.args, []
        return res
    def message(self, text):
        self.error.write(text + '\n')
    def exception(self):
        return (sys.exc_type, sys.exc_value)
    def exit(self, message='', status=1):
        if message:
            self.message(message)
        sys.exit(status)
    def shell(self, command, fork=0, inp=''):
        if self.verbose:
            self.message(command)
        if not fork:
            os.system(command)
        elif fork == 1:
            return os.popen(command, 'r').read()
        else:
            pipe = os.popen(command, 'w')
            pipe.write(inp)
            pipe.close()
    def read(self, *size):
        return apply(self.input.read, size)
    def readline(self):
        return self.input.readline()
    def readlines(self):
        return self.input.readlines()
    def write(self, text):
        self.output.write(text)
    def writelines(self, text):
        self.output.writelines(text)
    def main(self):
        res = None
        try:
            self.start()
            self.run()
            res = self.stop()
        except SystemExit:
            pass
        except:
            self.message('uncaught: ' + `self.exception()`)
            traceback.print_exc()
        self.closeApp()
        return res
    def start(self):
        if self.verbose: self.message(self.name + ' start.')
    def stop(self):
        if self.verbose: self.message(self.name + ' done.')
    def run(self): raise AppError, 'run must be redefined!'

