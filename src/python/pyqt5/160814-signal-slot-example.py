#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from PyQt5 import QtCore

class A(QtCore.QObject):
    my_signal = QtCore.pyqtSignal(int)
    def connectNotify(self, method):
        method_name = bytes(method.name()).decode('utf-8')
        print('connectNotify({})'.format(method_name))
        if not method_name in ['destroyed']:
            getattr(self, method_name).emit(11)
    def disconnectNotify(self, method):
        method_name = bytes(method.name()).decode('utf-8')
        print('disconnectNotify({})'.format(method_name))
        if not method_name in ['destroyed']:
            getattr(self, method_name).emit(22)
    def f(self, value):
        print('number of receivers = {}'.format(self.receivers(self.my_signal)))
        self.my_signal.emit(value)

class B(QtCore.QObject):
    def f(self, value):
        print('f({})'.format(value))
        print('sender = {}'.format(self.sender()))

if __name__ == '__main__':
    a = A()
    b = B()
    from PyQt5 import QtTest
    spy = QtTest.QSignalSpy(a.my_signal)
    a.my_signal.connect(b.f)
    a.f(10)
    a.my_signal.disconnect(b.f)
    a.f(20)
    print('QSignalSpy = {}'.format(list(spy)))

