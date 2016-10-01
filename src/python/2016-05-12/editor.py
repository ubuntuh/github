#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import math
import time

from PyQt4 import QtCore
from PyQt4 import QtGui

class MainWindow(QtGui.QMainWindow):
    """プログラムの GUI のメインウィンドウです。また、多くのウィジェットの根になります。"""
    def __init__(self, password):
        super().__init__()
        self._password = password # パスワードを平文で保持します。
        del password
        self.setWindowTitle('CryptoEditor')
        self.resize(640, 480)
        # self.setAttribute(QtCore.Qt.WA_TranslucentBackground)
        # self.setAutoFillBackground(True)
        """self.setStyleSheet('''
            QWidget {
                background: transparent;
                background-color: rgba(0, 0, 0, 100);
                /* background-color: transparent; */
                border: 1px solid rgba(255, 0, 0, 100);
                /* border-radius: 10px; */
                color: rgba(0, 222, 0, 255);
                /* margin: 5px; */
            }
            QMainWindow {
                background: transparent;
                background-color: red;
            }
            
            QProgressBar {
                text-align: center;
            }
            QProgressBar::chunk {
                background-color: rgba(0, 0, 128, 128);
                width: 0.5px;
            }
            
            QTabWidget::pane {
                border: 1px solid rgba(255, 0, 0, 100);
                border-radius: 10px;
            }
            QTabWidget::tab-bar {
                alignment: center;
                border: 10px solid rgba(255, 0, 0, 100);
                background: transparent;
                left: 0px;
            }
            
            QTabBar::tab {
                background: transparent;
                background-color: transparent;
                border: 2px solid rgba(255, 0, 0, 100);
                border-bottom: none;
                border-top-left-radius: 10px;
                border-top-right-radius: 10px;
                border-bottom-right-radius: 0px;
                border-bottom-left-radius: 0px;
                margin: 0px 1px 0px 1px;
            }
            QTabBar::tab:selected {
                border: 2px solid rgba(255, 0, 0, 255);
                border-bottom: none;
            }
            
            QTextEdit {
                background-color: transparent;
                border: none;
                selection-background-color: white;
                selection-color: black;
            }
            QSizeGrip {
                background-color: transparent;
                border: none;
            }
            QStatusBar {
                border-radius: 0px;
            }
            QLineEdit {
                background-color: transparent;
            }
            ''')"""
        self._show_message('Program started.')
        def init_file_menu():
            menu = self.sender()
            menu.clear()
            action = QtGui.QAction('New Document', self)
            action.setShortcut('Ctrl+N')
            action.setStatusTip('Create new document')
            def handle_new_document():
                self.tab_widget.open()
            action.triggered.connect(handle_new_document)
            del handle_new_document
            menu.addAction(action)
            action = QtGui.QAction('Open', self)
            action.setShortcut('Ctrl+O')
            action.setStatusTip('Open new file')
            def show_open_dialog(self):
                file_name = QtGui.QFileDialog.getOpenFileName(self, 'Open Document')
                self.tab_widget.open(file_name)
            action.triggered.connect(show_open_dialog)
            del show_open_dialog
            menu.addAction(action)
            action = QtGui.QAction('Save', self)
            action.setShortcut('Ctrl+S')
            action.setStatusTip('Save file')
            def save_file_somehow():
                widget = self.tab_widget.currentWidget()
                if widget.has_file:
                    widget.write_file()
                else:
                    self._show_save_dialog()
            action.triggered.connect(save_file_somehow)
            del save_file_somehow
            menu.addAction(action)
            action = QtGui.QAction('Save As...', self)
            action.setShortcut('Ctrl+Shift+S')
            action.setStatusTip('Save file with a name')
            action.triggered.connect(self._show_save_dialog)
            menu.addAction(action)
            action = QtGui.QAction('Close Document', self)
            action.setShortcut('Ctrl+W')
            action.setStatusTip('Close document')
            def f():
                index = self.tab_widget.currentIndex()
                self.tab_widget.removeTab(index)
            action.triggered.connect(f)
            menu.addAction(action)
            action = QtGui.QAction('Print', self)
            action.setShortcut('Ctrl+P')
            def f():
                # Todo: 印刷について行間を調節したい。
                widget = self.tab_widget.currentWidget()
                printer = QtGui.QPrinter()
                # 次の行の引数を QtGui.QPrinter.PdfFormat とするとアウトラインフォントではなくビットマップフォントで出力されてしまう場合がある。
                printer.setOutputFormat(QtGui.QPrinter.PostScriptFormat)
                widget.print_(printer)
                print('Printed.')
            action.triggered.connect(f)
            menu.addAction(action)
            action = QtGui.QAction('&Exit', self)
            action.setShortcut('Ctrl+Q')
            action.setStatusTip('Exit application')
            def f():
                self.close()
            action.triggered.connect(f)
            menu.addAction(action)
        def init_edit_menu():
            menu = self.sender()
            menu.clear()
            action = QtGui.QAction('Copy', self)
            action.setShortcut('Ctrl+C')
            def f():
                widget = self.tab_widget.currentWidget()
                widget.copy()
            action.triggered.connect(f)
            widget = self.tab_widget.currentWidget()
            if len(widget.textCursor().selectedText()) == 0:
                action.setEnabled(False)
            menu.addAction(action)
            action = QtGui.QAction('Paste', self)
            action.setShortcut('Ctrl+V')
            def f():
                widget = self.tab_widget.currentWidget()
                widget.paste()
            action.triggered.connect(f)
            if len(QtGui.QApplication.clipboard().text()) == 0:
                 action.setEnabled(False)
            menu.addAction(action)
            action = QtGui.QAction('Clear clipboard', self)
            def f():
                QtGui.QApplication.clipboard().clear(QtGui.QClipboard.Clipboard)
                self._show_message('Cleared clipboard.')
            action.triggered.connect(f)
            if len(QtGui.QApplication.clipboard().text()) == 0:
                 action.setEnabled(False)
            menu.addAction(action)
            menu.addSeparator()
            action = QtGui.QAction('Find', self)
            action.setShortcut('Ctrl+F')
            def f():
                search_bar.setFocus()
                search_bar.selectAll()
            action.triggered.connect(f)
            menu.addAction(action)
            menu.addSeparator()
            action = QtGui.QAction('Insert level 1 heading', self)
            action.setShortcut('F1')
            def insert_heading(level):
                hash_ = '#' * level
                text, is_ok = QtGui.QInputDialog.getText(self, 'Level {} heading'.format(level), 'Heading:', text='-')
                if is_ok:
                    widget = self.tab_widget.currentWidget()
                    widget.insertPlainText('{} {}\n\n'.format(hash_, text))
                    widget.ensureCursorVisible()
                    self._show_message('Level {} heading inserted.'.format(level))
            import functools
            action.triggered.connect(functools.partial(insert_heading, 1))
            menu.addAction(action)
            action = QtGui.QAction('Insert level 2 heading', self)
            action.setShortcut('F2')
            action.triggered.connect(functools.partial(insert_heading, 2))
            menu.addAction(action)
            action = QtGui.QAction('Insert level 3 heading', self)
            action.setShortcut('F3')
            action.triggered.connect(functools.partial(insert_heading, 3))
            menu.addAction(action)
            action = QtGui.QAction('Insert level 4 heading', self)
            action.setShortcut('F4')
            action.triggered.connect(functools.partial(insert_heading, 4))
            menu.addAction(action)
            action = QtGui.QAction('Insert level 5 heading', self)
            action.setShortcut('F5')
            action.triggered.connect(functools.partial(insert_heading, 5))
            menu.addAction(action)
            action = QtGui.QAction('Insert level 6 heading', self)
            action.setShortcut('F6')
            action.triggered.connect(functools.partial(insert_heading, 6))
            menu.addAction(action)
            action = QtGui.QAction('Insert date', self)
            action.setShortcut('Ctrl+Shift+D')
            def f():
                widget = self.tab_widget.currentWidget()
                import time
                string = '### {}\n\n'.format(time.strftime('%Y-%m-%d %a'))
                widget.insertPlainText(string)
                self._show_message('Date inserted.')
            action.triggered.connect(f)
            menu.addAction(action)
            action = QtGui.QAction('Insert list item', self)
            action.setShortcut('Ctrl+Shift+I')
            def f():
                widget = self.tab_widget.currentWidget()
                widget.insertPlainText('- ')
            action.triggered.connect(f)
            menu.addAction(action)
            menu.addSeparator()
            action = QtGui.QAction('Reset timer', self)
            def f():
                self._reset_timer()
            action.triggered.connect(f)
            menu.addAction(action)
        def init_view_menu():
            menu = self.sender()
            menu.clear()
            action = QtGui.QAction('Change window opacity...', self)
            def f():
                input_, is_ok = QtGui.QInputDialog.getDouble(self, 'Change window opacity', 'Enter opacity (0.20-1.00): \n  where\n    1.00 is completely opaque\n    and\n    0.00 is completely transparent', value=self.windowOpacity(), min=0.2, max=1.0, decimals=2)
                if is_ok:
                    self.setWindowOpacity(input_)
            action.triggered.connect(f)
            menu.addAction(action)
        def init_menu_bar():
            menu_bar = self.menuBar()
            menu = menu_bar.addMenu('&File')
            menu.aboutToShow.connect(init_file_menu)
            menu = menu_bar.addMenu('&Edit')
            menu.aboutToShow.connect(init_edit_menu)
            menu = menu_bar.addMenu('&View')
            menu.aboutToShow.connect(init_view_menu)
        init_menu_bar()
        del init_menu_bar
        def open_tab(file_name):
            self.tab_widget.open(file_name)
        def get_current_editor():
            return self.tab_widget.currentWidget()
        central_widget = QtGui.QWidget()
        v_box = QtGui.QVBoxLayout()
        v_box.setSpacing(1)
        v_box.setContentsMargins(0, 0, 0, 0)
        splitter = QtGui.QSplitter(QtCore.Qt.Horizontal, parent=self)
        self.browser = Browser(get_current_editor, open_tab, parent=splitter)
        self.toc = TOC(get_current_editor, parent=splitter)
        del get_current_editor
        def encrypt(string):
            import encryption
            encrypted = encryption.encrypt(string, self._password)
            return encrypted
        def decrypt(string):
            import encryption
            decrypted = encryption.decrypt(string, self._password)
            return decrypted
        search_bar = SearchBar(self)
        self.tab_widget = TabWidget(self.close, encrypt, decrypt, self._show_message, self.browser.update, self.toc.update, self.toc.update_position, parent=splitter)
        del encrypt, decrypt
        splitter.addWidget(self.browser)
        splitter.addWidget(self.tab_widget)
        splitter.addWidget(self.toc)
        splitter.setStretchFactor(0, 1)
        splitter.setStretchFactor(1, 2)
        splitter.setStretchFactor(2, 1)
        progress_bar = QtGui.QProgressBar(self)
        v_box.addWidget(progress_bar)
        # time_edit = QtGui.QDateTimeEdit(QtCore.QDateTime.currentDateTime())
        # time_edit.setDisplayFormat('yyyy-MM-dd ddd hh:mm')
        # time_edit.setCalendarPopup(True)
        # v_box.addWidget(time_edit)
        v_box.addWidget(splitter)
        v_box.addWidget(search_bar)
        central_widget.setLayout(v_box)
        self.setCentralWidget(central_widget)
        self.tab_widget.open()
        self._timer = Timer(self.close, self.setWindowTitle, progress_bar, parent=self)
        import configuration
        configuration.init(self)
    def event(self, event):
        if event.type() not in [QtCore.QEvent.Paint, QtCore.QEvent.UpdateRequest]:
            try:
                self._reset_timer()
            except:
                pass
        return super().event(event)
    def _reset_timer(self):
        self._timer.reset()
    def _show_message(self, string):
        status_bar = self.statusBar()
        status_bar.showMessage(string)
    def _show_save_dialog(self):
        widget = self.tab_widget.currentWidget()
        document_name = widget.document_name
        file_name = QtGui.QFileDialog.getSaveFileName(self, 'Save Document', document_name)
        if not file_name:
            return
        widget.write_file(file_name)
    def closeEvent(self, event):
        print('Window closing.')
        for i in range(self.tab_widget.count()):
            widget = self.tab_widget.widget(i)
            widget.prepare_close()

class SearchBar(QtGui.QLineEdit):
    def __init__(self, window):
        super().__init__()
        self._window = window
        self.setText('(Easy Find)')
    def keyPressEvent(self, event):
        if event.key() in [QtCore.Qt.Key_Return, QtCore.Qt.Key_Enter]:
            if event.modifiers() & QtCore.Qt.ShiftModifier:
                self._search(is_backward=True)
            else:
                self._search()
            return
        return super().keyPressEvent(event)
    def _message(self, string):
        self._window.statusBar().showMessage(string)
    def _search(self, *, is_backward=False):
        """暫定的な実装になっている。というのも、正規表現の利用とそうでないものが混在している。どちらに一本化することもできるが、正規表現に一本化した方が良いだろうと思っている。しかし差し迫った必要性がないので、暫定的な実装としてある。"""
        query = self.text()
        window = self._window
        tab_widget = window.tab_widget
        editor = tab_widget.currentWidget()
        old_cursor = editor.textCursor()
        old_position = old_cursor.position()
        if is_backward:
            is_found = editor.find(query, QtGui.QTextDocument.FindBackward)
        else:
            is_found = editor.find(query)
        new_cursor = editor.textCursor()
        new_position = new_cursor.position()
        block_number = new_cursor.blockNumber()
        if not is_found:
            message = ''
            if is_backward:
                message = ' (Searched backward.)'
            self._message('"' + query + '" was not found.' + message)
        else:
            text = editor.toPlainText()
            import re
            regex = re.compile(query, flags=re.MULTILINE)
            matches = []
            for match in regex.finditer(text):
                matches.append(match)
            number = -1
            for i, match in enumerate(matches):
                if match.end() == new_position:
                    number = i + 1
            num_matches = len(matches)
            message = 'Found at line ' + str(block_number + 1) + ', char ' + str(new_position) + '. (' + str(number) + ' of ' + str(num_matches) + ')'
            self._message(message)

class Timer(QtCore.QTimer):
    """ユーザが一定時間プログラムを操作しなかった場合に、自動的にプログラムを終了するためのタイマです。"""
    _limit_in_seconds = 15 * 60
    _tick_in_milliseconds = 1000
    def __init__(self, exit, set_window_title, progress_bar, *, parent):
        super().__init__(parent)
        self._exit = exit
        self._set_window_title = set_window_title
        self._progress_bar = progress_bar
        self._progress_bar.setFormat('%v s')
        self._progress_bar.setMinimum(0)
        self._progress_bar.setMaximum(self._limit_in_seconds)
        self.timeout.connect(self._handle_timeout)
        self._reset_sub()
        self.start(self._tick_in_milliseconds)
        self._handle_timeout()
    def _consider_exit(self):
        if time.time() - self._start > self._limit_in_seconds:
            self._do_exit()
            return
    def _do_exit(self):
        if hasattr(self, '_is_done_by_none'):
            return
        self._is_done_by_none = None
        string = time.strftime('%Y-%m-%d %a %H:%M:%S')
        print('Exiting program. Timer expired at ' + string + '.')
        self._exit()
    def _handle_timeout(self):
        elapsed = time.time() - self._start
        left = math.ceil(self._limit_in_seconds - elapsed)
        # self._set_window_title('CryptoEditor (' + str(math.ceil(left)) + ' s)')
        self._progress_bar.setValue(left)
        string = '{0:d}:{1:02d}'.format(left // 60, left % 60)
        self._progress_bar.setFormat(string)
        self._consider_exit()
    def reset(self):
        self._consider_exit()
        self._reset_sub()
    def _reset_sub(self):
        self._start = time.time()
        self._handle_timeout()

class TabWidget(QtGui.QTabWidget):
    def __init__(self, close_main_window, encrypt, decrypt, show_message, update_browser, update_toc, update_toc_position, *, parent):
        super().__init__(parent)
        self._close_main_window = close_main_window
        self._encrypt = encrypt
        self._decrypt = decrypt
        self._show_message = show_message
        self._update_browser = update_browser
        self._update_toc = update_toc
        self._update_toc_position = update_toc_position
        self._untitled_number = 0
        # self.setDocumentMode(True)
        self.setTabsClosable(True)
        def f(index):
            self.removeTab(index)
        self.tabCloseRequested.connect(f)
        def handle_changed():
            message = ''
            if self.count() >= 1:
                message = ' (' + self.tabText(self.currentIndex()) + ')'
            print('Current tab changed.' + message)
            self._update_browser()
            self._update_toc()
        self.currentChanged.connect(handle_changed)
        del handle_changed
    def open(self, file_name=''):
        for i in range(self.count()):
            widget = self.widget(i)
            if widget.has_file and widget.file_absolute_path == file_name:
                self.setCurrentWidget(widget)
                return
        widget = Editor(self._encrypt, self._decrypt, self._show_message, self._update_tab, self._update_browser, self._update_toc, self._update_toc_position, parent=self)
        if file_name:
            try:
                widget.read_file(file_name)
            except UnicodeDecodeError:
                QtGui.QMessageBox.critical(self, 'Error', 'Failed to open the file.\nMaybe you entered an wrong password.\n(UnicodeDecodeError)')
                return
        else:
            self._init_untitled(widget)
        self.addTab(widget, widget.document_name) # Slow.
        number_of_tabs = self.count()
        if number_of_tabs == 2:
            for i in range(number_of_tabs):
                tmp = self.widget(i)
                if not tmp is widget:
                    old = tmp
                    if not old.has_file and not old.toPlainText():
                        index = self.indexOf(old)
                        self.removeTab(index)
                    break
        self.setCurrentWidget(widget) # Slow.
        widget.setFocus()
        import configuration
        configuration.init(self)
    def _init_untitled(self, widget):
        widget.document_name = 'Untitled ' + str(self._untitled_number)
        self._untitled_number += 1
    def removeTab(self, index):
        if self.count() <= 1:
            self._close_main_window()
            return
        self.widget(index).prepare_close()
        super().removeTab(index)
    def _update_tab(self, widget):
        index = self.indexOf(widget)
        text = widget.document_name
        if widget.is_edited:
            # "The most common occurrence is the after position, and I think this is to prevent it from obscuring the name of the file."
            text += '*'
        self.setTabText(index, text)

class Editor(QtGui.QTextEdit):
    def __init__(self, encrypt, decrypt, show_message, update_tab, update_browser, update_toc, update_toc_position, *, parent):
        super().__init__(parent)
        self._encrypt = encrypt
        self._decrypt = decrypt
        self._show_message = show_message
        self._update_tab = update_tab
        self._update_browser = update_browser
        self._update_toc = update_toc
        self.has_file = False
        self.is_edited = False
        self.setAcceptRichText(False)
        # option = self.document().defaultTextOption()
        # option.setFlags(QtGui.QTextOption.ShowTabsAndSpaces)
        # self.document().setDefaultTextOption(option)
        self.cursorPositionChanged.connect(update_toc_position)
        self.textChanged.connect(self._handle_text_changed)
        import configuration
        configuration.init(self)
    def contextMenuEvent(self, event):
        menu = QtGui.QMenu()
        action = QtGui.QAction('Copy', self)
        action.triggered.connect(self.copy)
        if len(self.textCursor().selectedText()) == 0:
            action.setEnabled(False)
        menu.addAction(action)
        action = QtGui.QAction('Paste', self)
        action.triggered.connect(self.paste)
        if len(QtGui.QApplication.clipboard().text()) == 0:
             action.setEnabled(False)
        menu.addAction(action)
        menu.addSeparator()
        action = QtGui.QAction('Insert date', self)
        def f():
            import time
            string = '### ' + time.strftime('%Y-%m-%d %a') + '\n\n'
            self.insertPlainText(string)
        action.triggered.connect(f)
        menu.addAction(action)
        action = QtGui.QAction('Change font/font size...', self)
        def f():
            old_font = self.font()
            def fix(): # 環境によってはフォントが素直に維持されないようである。応急処置的に対処する。
                old_style = old_font.style()
                old_style_name = old_font.styleName()
                old_font.setStyle(old_style)
                if old_style == QtGui.QFont.StyleNormal and old_style_name == '':
                    old_font.setStyleName('Regular')
            fix()
            new_font, ok = QtGui.QFontDialog.getFont(old_font, self)
            if ok:
                self.setFont(new_font)
        action.triggered.connect(f)
        menu.addAction(action)
        action = QtGui.QAction('Help...', self)
        def f():
            text = 'Backspace: Deletes the character to the left of the cursor.\nDelete: Deletes the character to the right of the cursor.\nCtrl+C: Copy the selected text to the clipboard.\nCtrl+Insert: Copy the selected text to the clipboard.\nCtrl+K: Deletes to the end of the line.\nCtrl+V: Pastes the clipboard text into text edit.\nShift+Insert: Pastes the clipboard text into text edit.\nCtrl+X: Deletes the selected text and copies it to the clipboard.\nShift+Delete: Deletes the selected text and copies it to the clipboard.\nCtrl+Z: Undoes the last operation.\nCtrl+Y: Redoes the last operation.\nLeft: Moves the cursor one character to the left.\nCtrl+Left: Moves the cursor one word to the left.\nRight: Moves the cursor one character to the right.\nCtrl+Right: Moves the cursor one word to the right.\nUp: Moves the cursor one line up.\nDown: Moves the cursor one line down.\nPageUp: Moves the cursor one page up.\nPageDown: Moves the cursor one page down.\nHome: Moves the cursor to the beginning of the line.\nCtrl+Home: Moves the cursor to the beginning of the text.\nEnd: Moves the cursor to the end of the line.\nCtrl+End: Moves the cursor to the end of the text.\nAlt+Wheel: Scrolls the page horizontally (the Wheel is the mouse wheel).'
            QtGui.QMessageBox.information(self, 'Editing Key Bindings', text)
        action.triggered.connect(f)
        menu.addAction(action)
        menu.exec_(event.globalPos())
    def copy(self):
        selected = self.textCursor().selectedText()
        if len(selected) == 0:
            self._show_message('Failed to copy. Nothing selected.')
            return
        super().copy()
        clipboard = QtGui.QApplication.clipboard()
        text = clipboard.text()
        length = len(text)
        self._show_message('Copied {} characters: "{}".'.format(length, text))
    def event(self, event):
        if event.type() == QtCore.QEvent.ShortcutOverride:
            return True
        return super().event(event)
    def keyPressEvent(self, event):
        if event.key() == QtCore.Qt.Key_C and event.modifiers() & QtCore.Qt.ControlModifier:
            self.copy()
            return
        if event.key() == QtCore.Qt.Key_V and event.modifiers() & QtCore.Qt.ControlModifier:
            self.paste()
            return
        if event.key() == QtCore.Qt.Key_Plus and event.modifiers() & QtCore.Qt.ControlModifier:
            self.zoom_in()
            return
        if event.key() == QtCore.Qt.Key_Minus and event.modifiers() & QtCore.Qt.ControlModifier:
            self.zoom_out()
            return
        if event.key() in [QtCore.Qt.Key_Return, QtCore.Qt.Key_Enter] and not event.modifiers() & QtCore.Qt.ShiftModifier:
            number = self.textCursor().blockNumber()
            line = self.document().findBlockByLineNumber(number).text()
            if line.startswith('- '):
                self.insertPlainText('\n- ')
                self.ensureCursorVisible()
                return
        if event.key() == QtCore.Qt.Key_F12: # Todo: Test.
            cursor = self.textCursor()
            anchor = cursor.anchor()
            position = cursor.position()
            self.undo()
            cursor.beginEditBlock()
            self.redo()
            cursor.setPosition(anchor)
            cursor.setPosition(position, QtGui.QTextCursor.KeepAnchor)
            format = QtGui.QTextCharFormat()
            format.setFontItalic(True)
            format.setBackground(QtCore.Qt.red)
            format.setForeground(QtCore.Qt.green)
            format.setFontWeight(QtGui.QFont.Bold)
            cursor.setCharFormat(format)
            cursor.endEditBlock()
            return
        return super().keyPressEvent(event)
    def _handle_text_changed(self):
        if not self.is_edited:
            self.is_edited = True
            self._update_tab(self)
        self._update_toc()
    def mouseDoubleClickEvent(self, event):
        def is_space(character):
            return character.isspace()
        def is_numeric(character):
            if character in ['+', '-']:
                # 2000-12-31 といった文字列をしばしば扱うためこのような実装である方が都合が良い。
                # 左側の複数の記号、例えば '++0' や、右側の記号、例えば '0+' を含める実装になっているが、この動作は不可解であって理想的ではない。しかしながら、実装を簡略にして見通しの良さを保つために、それを不可解な仕様のままにしている。
                return True
            return character.isnumeric()
        def is_ascii_letter(character):
            import string
            return character in string.ascii_letters
        def is_hiragana(character):
            value = ord(character)
            return 0x3040 <= value and value <= 0x309f
        def is_katakana(character):
            value = ord(character)
            return 0x30a0 <= value and value <= 0x30ff
        def is_kanji(character):
            value = ord(character)
            return 0x4e00 <= value and value <= 0x9faf
        def is_others(character):
            functions = [is_space, is_numeric, is_ascii_letter, is_hiragana, is_katakana, is_kanji]
            for f in functions:
                if f(character):
                    return False
            return True
        position = self.cursorForPosition(event.pos()).position()
        text = self.toPlainText()
        if position == len(text):
            if len(text):
                position -= 1
            else:
                return
        character = text[position]
        functions = [is_space, is_numeric, is_ascii_letter, is_hiragana, is_katakana, is_kanji, is_others]
        is_same_type = None
        for f in functions:
            if f(character):
                is_same_type = f
                break
        left = position
        while 0 < left and is_same_type(text[left - 1]):
                left -= 1
        right = position
        while right < len(text) - 1 and is_same_type(text[right + 1]):
                right += 1
        cursor = self.textCursor()
        cursor.setPosition(left)
        cursor.setPosition(right + 1, QtGui.QTextCursor.KeepAnchor)
        self.setTextCursor(cursor)
    def paste(self):
        clipboard = QtGui.QApplication.clipboard()
        text = clipboard.text()
        length = len(text)
        if length == 0:
            self._show_message('Failed to paste. Nothing in clipboard.')
            return
        super().paste()
        self._show_message('Pasted {} characters: "{}".'.format(length, text))
    def prepare_close(self):
        if self.is_edited:
            print("Modified data discarded at closing. (document '" + self.document_name + "')")
    def read_file(self, file_name):
        start_time = time.time()
        print('Reading file. (' + file_name + ')')
        import os
        is_file = os.path.isfile(file_name)
        if not is_file:
            print('is_file:', is_file)
            return
        with open(file_name, 'rb') as file:
            encoded = file.read()
        decrypted = self._decrypt(encoded)
        self.has_file = True
        self.file_absolute_path = file_name
        self.document_name = os.path.basename(file_name)
        self.setPlainText(decrypted)
        self.is_edited = False
        self._update_tab(self)
        self._show_message('Loaded "{}" in {} s.'.format(file_name, '{:.3f}'.format(time.time() - start_time)))
    def show_position(self, position):
        self.moveCursor(QtGui.QTextCursor.End)
        cursor = self.textCursor()
        cursor.setPosition(position)
        self.setTextCursor(cursor)
    def wheelEvent(self, event):
        if event.modifiers() & QtCore.Qt.ControlModifier:
            if event.delta() > 0:
                self.zoom_in()
            else:
                self.zoom_out()
        else:
            super().wheelEvent(event)
            if event.isAccepted():
                # この場合、MainWindow.event() が呼び出されないようであり、現在の実装ではタイマをリセットするためにそれは不都合であるので、ここで解決する。
                event.ignore()
    def write_file(self, file_name=''):
        start_time = time.time()
        if not file_name:
            if self.has_file:
                file_name = self.file_absolute_path
        print('Writing file. (' + file_name + ')')
        import os
        is_file = os.path.isfile(file_name)
        if is_file:
            already_exist = True
        text = self.toPlainText()
        encrypted = self._encrypt(text)
        with open(file_name, 'wb') as file:
            file.write(encrypted)
        self.has_file = True
        self.file_absolute_path = file_name
        self._update_browser()
        self.document_name = os.path.basename(file_name)
        self.is_edited = False
        self._update_tab(self)
        self._show_message('Successfully saved at {} in {} s.'.format(time.ctime(os.path.getmtime(file_name)), '{:.3f}'.format(time.time() - start_time)))
    def _zoom(self, delta):
        font = self.font()
        old_point_size = font.pointSize()
        if old_point_size != -1:
            new_point_size = old_point_size + delta
            if new_point_size <= 0:
                new_point_size = 1
            font.setPointSize(new_point_size)
            self.setFont(font)
            self.ensureCursorVisible()
            self._show_message('Font size = {} points.'.format(new_point_size))
        else:
            print('Failed to zoom.')
    def zoom_in(self):
        self._zoom(1)
    def zoom_out(self):
        self._zoom(-1)

class Browser(QtGui.QListWidget):
    _forwards = []
    _prevs = []
    def __init__(self, get_current_editor, open_tab, *, parent):
        super().__init__(parent)
        self._get_current_editor = get_current_editor
        self._open_tab = open_tab
        self.itemClicked.connect(self._handle_item_clicked)
        import configuration
        configuration.init(self)
    def _handle_item_clicked(self, item):
        if hasattr(item, 'is_dummy_by_none'):
            return
        import os
        if hasattr(item, 'is_parent_by_none'):
            self._forwards = []
            self._prevs.append(self._directory)
            self._directory = os.path.dirname(self._directory)
            self._update_files()
            return
        if hasattr(item, 'is_dir_by_none'):
            self._forwards = []
            self._prevs.append(self._directory)
            self._directory = item.absolute_path
            self._update_files()
        if hasattr(item, 'is_file_by_none'):
            self._open_tab(item.absolute_path)
    def mousePressEvent(self, event):
        import os
        if event.buttons() == QtCore.Qt.XButton1:
            if len(self._prevs) and os.path.isdir(self._prevs[-1]):
                self._forwards.append(self._directory)
                self._directory = self._prevs[-1]
                self._prevs = self._prevs[:-1]
                self._update_files()
        elif event.buttons() == QtCore.Qt.XButton2:
            if len(self._forwards) and os.path.isdir(self._forwards[-1]):
                self._prevs.append(self._directory)
                self._directory = self._forwards[-1]
                self._forwards = self._forwards[:-1]
                self._update_files()
        else:
            super().mousePressEvent(event)
    def update(self):
        widget = self._get_current_editor()
        if widget is None:
            self.clear()
            return
        import os
        if not widget.has_file:
            self._path = os.getcwd()
        else:
            self._path = widget.file_absolute_path
        self._directory = os.path.dirname(self._path)
        self._update_files()
    def _update_files(self):
        print('File browser updated. (' + self._directory + ')')
        self.clear()
        item = QtGui.QListWidgetItem()
        item.is_dummy_by_none = None
        text = self._directory
        item.setText(text)
        self.addItem(item)
        indent = '    '
        item = QtGui.QListWidgetItem()
        item.is_dummy_by_none = None
        item.setText(indent + '.')
        self.addItem(item)
        import os
        parent = os.path.dirname(self._directory)
        if not os.path.samefile(parent, self._directory):
            item = QtGui.QListWidgetItem()
            item.is_parent_by_none = None
            item.setText(indent + '..')
            self.addItem(item)
        entries = os.listdir(self._directory)
        entries.sort()
        directories = []
        files = []
        for entry in entries:
            path = os.path.join(self._directory, entry)
            if os.path.isdir(path):
                directories.append(path)
            elif os.path.isfile(path):
                files.append(path)
            else:
                print('?', path)
        for entry in directories:
            item = QtGui.QListWidgetItem()
            item.is_dir_by_none = None
            item.absolute_path = entry
            basename = os.path.basename(entry)
            item.setText(indent + basename + os.sep)
            self.addItem(item)
        for entry in files:
            item = QtGui.QListWidgetItem()
            item.is_file_by_none = None
            item.absolute_path = entry
            basename = os.path.basename(entry)
            stat = os.stat(entry)
            size_string = format(stat.st_size, ',d')
            text = indent + basename + ' (' + size_string + ')'
            if os.path.samefile(entry, self._path):
                current_item = item
            item.setText(text)
            self.addItem(item)
        if 'current_item' in locals():
            self.setCurrentItem(current_item)

class TOC(QtGui.QListWidget):
    def __init__(self, get_current_editor, *, parent):
        super().__init__(parent)
        self._get_current_editor = get_current_editor
        self.itemClicked.connect(self._handle_item_clicked)
        import configuration
        configuration.init(self)
    def _handle_item_clicked(self, item):
        widget = self._get_current_editor()
        if widget is None:
            return
        if hasattr(item, 'is_total_by_none'):
            item.start = len(widget.toPlainText().rstrip())
        widget.show_position(item.start)
        widget.setFocus()
    def update(self):
        if hasattr(self, '_timer'):
            self._timer.stop()
            self._timer.deleteLater()
        self._timer = QtCore.QTimer()
        self._timer.setSingleShot(True)
        self._timer.start(500)
        self._timer.timeout.connect(self._update_data)
    def _update_data(self):
        widget = self._get_current_editor()
        if widget is None:
            self.clear()
            return
        text = widget.toPlainText()
        self._total = len(text)
        import re
        founds = []
        for i in range(1, 7):
            tag = '^{} (.*)$'.format('#' * i)
            regex = re.compile(tag, flags=re.MULTILINE)
            matches = []
            for match in regex.finditer(text):
                matches.append((match.start(), match.end(), i, match.group(1)))
            for j in range(len(matches)):
                if j + 1 < len(matches):
                    next = matches[j + 1][0]
                else:
                    next = self._total
                length = next - matches[j][0]
                matches[j] = matches[j] + (length, )
            founds += matches
        founds.sort()
        self.data = []
        for x in founds:
            item = {}
            item['start'] = x[0]
            item['end'] = x[1]
            item['level'] = x[2]
            item['string'] = x[3]
            item['length'] = x[4]
            self.data.append(item)
        self._update_display()
    def _update_display(self):
        self.clear()
        item = QtGui.QListWidgetItem()
        item.is_total_by_none = None
        item.setText('(Total {} characters.)'.format(self._total))
        self.addItem(item)
        for x in self.data:
            item = QtGui.QListWidgetItem()
            item.start = x['start']
            indent = '    ' * (x['level'] - 1)
            text = indent + x['string'] + ' (' + str(x['length']) + ')'
            item.setText(text)
            self.addItem(item)
        self.update_position()
    def update_position(self):
        if hasattr(self, '_position_timer'):
            self._position_timer.stop()
            self._position_timer.deleteLater()
        self._position_timer = QtCore.QTimer()
        self._position_timer.setSingleShot(True)
        self._position_timer.start(250)
        self._position_timer.timeout.connect(self._update_position_sub)
    def _update_position_sub(self):
        if not hasattr(self, 'data'):
            return
        position = self._get_current_editor().textCursor().position()
        last_index = len(self.data) - 1
        for i, x in enumerate(self.data):
            start = x['start']
            end = start + x['length']
            widget = self.item(i + 1)
            if start <= position and position < end:
                self.setCurrentItem(widget)
            elif i == last_index and position == end:
                self.setCurrentItem(widget)

def main():
    def tryEnableTaskbarIcon():
        import platform
        if platform.system() == 'Windows':
            import random
            id = str(random.random())
            import ctypes
            ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID(id)
    tryEnableTaskbarIcon()
    import sys
    app = QtGui.QApplication(sys.argv)
    def setWindowIcon(widget):
        icon = QtGui.QIcon()
        for size in [64]:
            pixmap = QtGui.QPixmap(size, size)
            pixmap.fill(QtCore.Qt.red)
            icon.addPixmap(pixmap)
        widget.setWindowIcon(icon)
    setWindowIcon(app)
    print('Asking password.')
    password, is_ok = QtGui.QInputDialog.getText(None, 'CryptoEditor', 'Enter password:', mode=QtGui.QLineEdit.Password)
    if is_ok:
        print('User password temporary remembered.')
        MainWindow(password).show()
        sys.exit(app.exec_())
    else:
        print('Password input canceled.')

if __name__ == '__main__':
    main()
