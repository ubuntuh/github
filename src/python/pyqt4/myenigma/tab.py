#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from PyQt4.QtGui import *
class Tab1Widget(QWidget):
    def __init__(self, parent=None):
        super(Tab1Widget, self).__init__()
        closeBtn = QPushButton('Close')
        closeBtn.clicked.connect(parent.close)
        hbox = QHBoxLayout()
        hbox.addWidget(closeBtn)
        self.setLayout(hbox)
class Tab2Widget(QWidget):
    def __init__(self, parent=None):
        super(Tab2Widget, self).__init__()
        closeBtn = QPushButton('Close')
        closeBtn.clicked.connect(parent.close)
        closeBtn2 = QPushButton('Close2')
        closeBtn.clicked.connect(parent.close)
        hbox = QHBoxLayout()
        hbox.addWidget(closeBtn)
        hbox.addWidget(closeBtn2)
        self.setLayout(hbox)
class UI(QWidget):
    def __init__(self):
        super(UI, self).__init__()
        self.initUI()
    def initUI(self):
        qtab = QTabWidget()
        qtab.addTab(Tab1Widget(parent=self), 'Tab1')
        qtab.addTab(Tab2Widget(parent=self), 'Tab2')
        hbox = QHBoxLayout()
        hbox.addWidget(qtab)
        self.setLayout(hbox)
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Tab Layout')
        self.show()
def main():
    app = QApplication(sys.argv)
    ui = UI()
    sys.exit(app.exec_())
if __name__ == "__main__":
    main()
