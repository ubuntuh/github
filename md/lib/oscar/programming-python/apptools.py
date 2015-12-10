#!/usr/bin/python
import sys, os, string
from app import *
from internal import *
from interact import *
from redirect import *

class TestInteractiveApp(RedirectInternalApp, InteractiveApp):
    run = InteractiveApp.run

class TestMenuApp(MenuDictApp, RedirectInternalApp):
    __init__ = RedirectInternalApp.__init__
    stop = RedirectInternalApp.stop
    closeApp = RedirectInternalApp.closeApp

def _buildArgs(args):
    res = []
    for arg in args:
        if type(arg) in [type([]), type(())]:
            res = res + _buildArgs(arg)
        elif type(arg) != type(''):
            res.append('arg')
        else:
            res = res + string.split(arg)
    return res
def appCall(appClass, *args):
    save_argv = sys.argv
    sys.argv = [appClass.__name__] + _buildArgs(args)
    result = appClass().main()
    sys.argv = save_argv
    return result
def appRun(script, *args):
    arglist = _buildArgs(args)
    cmdline = script + '' + string.join(arglist)
    return os.popen(cmdline, 'r').read()

class ScriptPipe:
    def __init__(self, cmdline, mode):
        self.pipe = os.popen(cmdline, mode)
    def __getattr__(self, name):
        return getattr(self.pipe, name)
    def cmdline(self, script, args):
        return script + '' + string.join(_buildArgs(args))

class ScriptOutput(ScriptPipe):
    def __init__(self, script, *args):
        ScriptPipe.__init__(self.cmdline(script, args) + " -o -", 'r')

class ScriptInput(ScriptPipe):
    def __init__(self, script, *args):
        ScriptPipe.__init__(self.cmdline(script, args) + " -i -", 'w')

def _redirected1(input, function, args):
    save_streams = sys.stdin, sys.stdout
    sys.stdin = Input(input)
    sys.stdout = Output()
    try:
        apply(function, args)
    except:
        sys.stderr.write('error in function! ')
        sys.stderr.write(`sys.exc_type` + ',' + `sys.exc_value` + '\n')
    result = sys.stdout.text
    sys.stdin, sys.stdout = save_streams
    return result

class FuncTestApp(RedirectInternalApp):
    def __init__(self, input, func, args):
        RedirectInternalApp.__init__(self, input)
        self.call = func, args
    def run(self):
        try:
            apply(apply, self.call)
        except:
            self.message('error in function!' + `self.exception()`)

def redirected(input, function, args):
    return FuncTestApp(input, function, args).main()

def _self_test():
    print raw_input('here we go => ')
    def testfunc(N):
        ans = raw_input('Enter? ')
        for i in range(N):
            print ans
        sys.stdout.write(sys.stdin.readline())
        print "Ni!" * N
    input = 'Spam!\nA shrubbery...'
    output = redirected(input, testfunc, (5,))
    ans = raw_input('welcome back => ')
    print 'got it =>', ans
    print 'testfunc output =>\n', output
    def tee():
        sys.stdout.writelines(sys.stdin.readlines())
    def tee2():
        text = sys.stdin.readlines()
        print text
        for line in text:
            sys.stdout.write('> ')
            print line,
    print 'tee output =>\n',  redirected("spam\nSpam\nSPAM!\n", tee,  ())
    print 'tee2 output =>\n', redirected("spam\nSpam\nSPAM!",   tee2, ())
    class EchoApp(TestInteractiveApp):
        def evalCommand(self, command):
            return 'got this -> ' + string.upper(command)
    output = EchoApp("guido\nis\ngod\n").main()
    print 'EchoApp output =>\n', output
    class DemoApp(TestMenuApp):
        menu = {
                'hello' : lambda: 'Hello world!',
                'play'  : lambda: 'Ni' * 4,
                'bye'   : lambda: 0,
        }
    output = DemoApp("hello\nspam\nplay\nbye").main()
    print 'DemoApp output ->\n', output
if __name__ == '__main__': _self_test()

