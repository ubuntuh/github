#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtCore, QtGui

class PasswordDialog(QtGui.QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('CryptoEditor')
        vbox = QtGui.QVBoxLayout()
        hbox = QtGui.QHBoxLayout()
        label = QtGui.QLabel('Enter password:')
        hbox.addWidget(label)
        lineEdit = QtGui.QLineEdit(self)
        lineEdit.setEchoMode(QtGui.QLineEdit.Password)
        hbox.addWidget(lineEdit)
        vbox.addLayout(hbox)
        hbox = QtGui.QHBoxLayout()
        hbox.addStretch(1)
        button = QtGui.QPushButton('Cancel', self)
        button.clicked.connect(self.handleCancel)
        hbox.addWidget(button)
        button = QtGui.QPushButton('OK', self)
        button.setDefault(True)
        button.clicked.connect(self.handleOK)
        hbox.addWidget(button)
        vbox.addLayout(hbox)
        self.setLayout(vbox)
    def handleCancel(self):
        self.reject()
    def handleOK(self):
        self.accept()

class MainWindow(QtGui.QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.setWindowTitle('CryptoEditor')
        self.resize(640, 480)
        self.statusBar().showMessage('(status bar)')
        menuBar = self.menuBar()
        menu = menuBar.addMenu('&File')
        action = QtGui.QAction(QtGui.QIcon('open.png'), 'Open', self)
        action.setShortcut('Ctrl+O')
        action.setStatusTip('Open new File')
        action.triggered.connect(self.showOpenDialog)
        menu.addAction(action)
        action = QtGui.QAction(QtGui.QIcon('open.png'), 'Save', self)
        action.setShortcut('Ctrl+S')
        action.setStatusTip('Save File')
        action.triggered.connect(self.showSaveDialog)
        menu.addAction(action)
        action = QtGui.QAction(QtGui.QIcon('exit.png'), '&Exit', self)
        action.setShortcut('Ctrl+Q')
        action.setStatusTip('Exit application')
        action.triggered.connect(QtGui.qApp.quit)
        menu.addAction(action)
        splitter = QtGui.QSplitter(QtCore.Qt.Horizontal)
        splitter.addWidget(QtGui.QTextEdit(self))
        self.tabWidget = TabWidget()
        splitter.addWidget(self.tabWidget)
        splitter.addWidget(QtGui.QTextEdit(self))
        self.setCentralWidget(splitter)
    def showOpenDialog(self):
        fileName = QtGui.QFileDialog.getOpenFileName(self, 'Open Document')
        print('fileName =', fileName)
        import os.path
        isfile = os.path.isfile(fileName)
        print('isfile =', isfile)
        if not isfile:
            return
        file = open(fileName, 'r')
        with file:
            data = file.read()
            print(data)
    def showSaveDialog(self):
        fileName = QtGui.QFileDialog.getSaveFileName(self, 'Save Document', 'Untitled.md')
        print('fileName =', fileName)

class TabWidget(QtGui.QTabWidget):
    def __init__(self):
        super().__init__()
        tmp = MainEdit()
        self.addTab(tmp, "aaaa")

class MainEdit(QtGui.QTextEdit):
    def __init__(self):
        super().__init__()

def main():
    app = QtGui.QApplication(sys.argv)
    dialog = PasswordDialog()
    result = dialog.exec_()
    if result == QtGui.QDialog.Accepted:
        window = MainWindow()
        window.show()
        sys.exit(app.exec_())
if __name__ == '__main__':
    main()
