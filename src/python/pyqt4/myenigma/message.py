#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PyQt4.QtCore import *
from PyQt4.QtGui import *
class UI(QMainWindow):
    def __init__(self):
        super(UI, self).__init__()
        self.initUI()
    def initUI(self):
        result = QMessageBox.question(self, "Question", "PyQt に慣れましたか？", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if result == QMessageBox.Yes:
            print("Selected Yes.")
        else:
            print("Selected No.")
        QMessageBox.warning(self, "Warning", "something wrong")
        QMessageBox.information(self, "Information", "Please contact at example@example.com")
        QMessageBox.critical(self, "Critical", "Oh my god.")
        QMessageBox.about(self, "About", "Ver1.0")
        self.show()
def main():
    app = QApplication(sys.argv)
    ui = UI()
    sys.exit(app.exec_())
if __name__ == "__main__":
    main()
