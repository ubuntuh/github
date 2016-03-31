#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtGui
from PyQt4 import QtCore
value = 0
dv = 1
bar = None
def countup():
    global value
    global var
    global dv
    # if value <= 100:
    value += dv
    bar.setValue(value)
    if value <= 0 or 100 <= value:
        dv *= -1
def main():
    app = QtGui.QApplication(sys.argv)
    w = QtGui.QWidget()
    w.resize(250, 150)
    w.setWindowTitle("ProgressBarSample")
    global bar
    bar = QtGui.QProgressBar(w)
    bar.resize(200, 30)
    bar.setValue(0)
    bar.move(20, 50)
    timer = QtCore.QTimer()
    QtCore.QObject.connect(timer, QtCore.SIGNAL("timeout()"), countup)
    timer.start(50)
    w.show()
    sys.exit(app.exec_())
if __name__ == "__main__":
    main()
