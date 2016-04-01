#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PyQt4.QtGui import *
class Example(QWidget):
    def __init__(self):
        super(Example, self).__init__()
        self.initUI()
    def initUI(self):
        title = QLabel("Title")
        author = QLabel("Author")
        review = QLabel("Review")
        titleEdit = QLineEdit()
        authorEdit = QLineEdit()
        reviewEdit = QLineEdit()
        grid = QVBoxLayout()
        self.groupBox = QGroupBox("Header")
        orivbox = QVBoxLayout()
        layout1 = QHBoxLayout()
        layout1.addWidget(title)
        layout1.addWidget(titleEdit)
        layout2 = QHBoxLayout()
        layout2.addWidget(author)
        layout2.addWidget(authorEdit)
        orivbox.addLayout(layout1)
        orivbox.addLayout(layout2)
        self.groupBox.setLayout(orivbox)
        grid.addWidget(self.groupBox)
        self.groupBox2 = QGroupBox("Main")
        mainbox = QVBoxLayout()
        mainbox.addWidget(review)
        mainbox.addWidget(reviewEdit)
        self.groupBox2.setLayout(mainbox)
        grid.addWidget(self.groupBox2)
        self.setLayout(grid)
        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle("Group box sample")
        self.show()
def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
if __name__ == "__main__":
    main()
