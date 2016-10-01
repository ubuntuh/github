#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from PyQt4 import QtGui

print('Configuring.')

import platform
_is_linux = platform.system() == 'Linux'
_is_windows = platform.system() == 'Windows'
_is_mac = platform.system() == 'Darwin'
del platform

_font_database = QtGui.QFontDatabase()
_font_families = _font_database.families()


def init(object_):
    class_name = type(object_).__name__
    if class_name == 'MainWindow':
        object_.setWindowOpacity(0.8)
    if class_name == 'Editor':
        if _is_linux:
            font = object_.font()
            font.setPointSize(15)
            object_.setFont(font)
        if _is_windows and 'メイリオ' in _font_families:
            font = QtGui.QFont('メイリオ', 12)
            object_.setFont(font)
    if class_name in ['TabWidget', 'Browser', 'TOC']:
        if _is_windows and 'メイリオ' in _font_families:
            font = QtGui.QFont('メイリオ', 10)
            object_.setFont(font)

print('    Configuration done.')
