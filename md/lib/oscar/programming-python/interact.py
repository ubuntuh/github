#!/usr/bin/python
import string
from app import App, AppError

class InteractiveApp(App):
    def run(self):
        while 1:
            command = self.readCommand()
            if not command:
                break
            result = self.evalCommand(command)
            if result == 0:
                break
            self.printResult(result)
    def readCommand(self, prompt='?'):
        try:
            return raw_input(prompt)
        except:
            return None
    def printResult(self, res):
        if res not in [1, None]:
            print res
    def evalCommand(self, command):
        raise AppError, 'evalCommand must be redefined!'

class MenuApp(InteractiveApp):
    def readCommand(self):
        print ('\n\tMENU...')
        self.showOptions()
        return InteractiveApp.readCommand(self, '==>')
    def evalCommand(self, cmd):
        try:
            return self.runOption(cmd)
        except:
            print 'what? "%s"?\ntry again...' % cmd
    def showOptions(self): raise AppError, 'showOptions undefined!'
    def runOptions(self): raise AppError, 'runOptions undefined!'

class MenuDictApp(MenuApp):
    def showOptions(self):
        options = self.menu.keys()
        options.sort()
        for cmd in options: print '\t\t' + cmd
    def runOption(self, cmd):
        return self.menu[cmd]()

class MenuListApp(MenuApp):
    def showOptions(self):
        for i in range(len(self.menu)):
            print '\t\t%d) %s' % (i, self.menu[i][0])
    def runOption(self, cmd):
        return self.menu[string.atoi(cmd)][1]()

class MenuClassApp(MenuApp):
    def readCommand(self):
        return self.menu.readCommand()

