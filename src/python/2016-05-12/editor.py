#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from PyQt4 import QtCore
from PyQt4 import QtGui

class PasswordDialog(QtGui.QDialog):
    """ユーザにパスワードを尋ねるダイアログです。編集する文書の暗号化と復号の際にこのパスワードが用いられます。"""
    def __init__(self):
        super().__init__()
        self.setWindowTitle('CryptoEditor')
        v_box = QtGui.QVBoxLayout()
        h_box = QtGui.QHBoxLayout()
        label = QtGui.QLabel('Enter password:')
        h_box.addWidget(label)
        line_edit = QtGui.QLineEdit(self)
        line_edit.setEchoMode(QtGui.QLineEdit.Password)
        h_box.addWidget(line_edit)
        self._line_edit = line_edit
        v_box.addLayout(h_box)
        h_box = QtGui.QHBoxLayout()
        h_box.addStretch(1)
        button = QtGui.QPushButton('Cancel', self)
        def handle_cancel():
            self.reject()
        button.clicked.connect(handle_cancel)
        del handle_cancel
        h_box.addWidget(button)
        button = QtGui.QPushButton('OK', self)
        button.setDefault(True)
        def handle_ok():
            self.password = self._line_edit.text()
            self.accept()
        button.clicked.connect(handle_ok)
        del handle_ok
        h_box.addWidget(button)
        v_box.addLayout(h_box)
        self.setLayout(v_box)

class MainWindow(QtGui.QMainWindow):
    """プログラムの GUI のメインウィンドウです。また、多くのウィジェットの根になります。"""
    def __init__(self, password):
        super().__init__()
        self._password = password # パスワードを平文で保持します。
        del password
        self.setWindowTitle('CryptoEditor')
        self.resize(640, 480)
        status_bar = QtGui.QStatusBar(self)
        status_bar.showMessage('Program started.')
        self.setStatusBar(status_bar)
        def init_menu_bar():
            menu_bar = self.menuBar()
            menu = menu_bar.addMenu('&File')
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
                if self.tab_widget.count() <= 1:
                    self.close()
                    return
                index = self.tab_widget.currentIndex()
                self.tab_widget.widget(index).handle_close()
                self.tab_widget.removeTab(index)
            action.triggered.connect(f)
            menu.addAction(action)
            action = QtGui.QAction('&Exit', self)
            action.setShortcut('Ctrl+Q')
            action.setStatusTip('Exit application')
            def f():
                self.close()
            action.triggered.connect(f)
            menu.addAction(action)
            menu = menu_bar.addMenu('&Edit')
            action = QtGui.QAction('Reset timer', self)
            def f():
                self.reset_timer()
            action.triggered.connect(f)
            del f
            menu.addAction(action)
        init_menu_bar()
        del init_menu_bar
        def open_tab(file_name):
            self.tab_widget.open(file_name)
        def get_current_editor():
            return self.tab_widget.currentWidget()
        self.browser = Browser(get_current_editor, open_tab, parent=self)
        self.toc = TOC(get_current_editor, parent=self)
        del get_current_editor
        def encrypt(string):
            import encryption
            encrypted = encryption.encrypt(string, self._password)
            return encrypted
        def decrypt(string):
            import encryption
            decrypted = encryption.decrypt(string, self._password)
            return decrypted
        self.tab_widget = TabWidget(encrypt, decrypt, self.reset_timer, self.browser.update, self.toc.update)
        del encrypt, decrypt
        splitter = QtGui.QSplitter(QtCore.Qt.Horizontal)
        splitter.addWidget(self.browser)
        splitter.addWidget(self.tab_widget)
        splitter.addWidget(self.toc)
        self.setCentralWidget(splitter)
        self.tab_widget.open()
        self._timer = Timer(self.close, self.setWindowTitle, parent=self)
    def reset_timer(self):
        self._timer.reset()
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
            widget.handle_close()

class Timer(QtCore.QTimer):
    def __init__(self, exit, set_window_title, parent=None):
        super().__init__(parent)
        self._exit = exit
        self._set_window_title = set_window_title
        self.timeout.connect(self._handle_timeout)
        self.initial_time = 15 * 60 + 1
        self.reset()
        self.start(1000)
    def _handle_timeout(self):
        self._seconds_left -= 1
        self._set_window_title('CryptoEditor (' + str(self._seconds_left) + ')')
        if self._seconds_left <= 0:
            import time
            time_string = time.strftime('%Y-%m-%d %a %H:%M:%S')
            print('Exiting program. Timer expired at ' + time_string + '.')
            # QtGui.qApp.quit()
            self._exit()
    def reset(self):
        self._seconds_left = self.initial_time

class TabWidget(QtGui.QTabWidget):
    def __init__(self, encrypt, decrypt, reset_timer, update_browser, update_toc):
        super().__init__()
        self._encrypt = encrypt
        self._decrypt = decrypt
        self._reset_timer = reset_timer
        self._update_browser = update_browser
        self._update_toc = update_toc
        self._untitled_number = 0
        def handle_changed():
            print('QTabWidget - currentChanged')
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
        widget = Editor(self._encrypt, self._decrypt, self._reset_timer, self._update_tab, self._update_browser, self._update_toc)
        if file_name:
            try:
                widget.read_file(file_name)
            except UnicodeDecodeError:
                QtGui.QMessageBox.critical(self, 'Error', 'Failed to open the file.\nMaybe you entered an wrong password.\n(UnicodeDecodeError)')
                return
            number_of_tabs = self.count()
            if number_of_tabs == 1:
                old = self.currentWidget()
                if not old.has_file and not old.toPlainText():
                    index = self.indexOf(old)
                    self.removeTab(index)
        else:
            self._init_untitled(widget)
        self.addTab(widget, widget.document_name)
        self.setCurrentWidget(widget)
        widget.setFocus()
        import configuration
        configuration.init(self)
    def _init_untitled(self, widget):
        widget.document_name = 'Untitled ' + str(self._untitled_number)
        self._untitled_number += 1
    def _update_tab(self, widget):
        index = self.indexOf(widget)
        text = widget.document_name
        if widget.is_edited:
            text += '*'
        self.setTabText(index, text)

class Editor(QtGui.QTextEdit):
    def __init__(self, encrypt, decrypt, reset_timer, update_tab, update_browser, update_toc):
        super().__init__()
        self._encrypt = encrypt
        self._decrypt = decrypt
        self._reset_timer = reset_timer
        self._update_tab = update_tab
        self._update_browser = update_browser
        self._update_toc = update_toc
        self.has_file = False
        self.is_edited = False
        self.setAcceptRichText(False)
        self.textChanged.connect(self._handle_text_changed)
        import configuration
        configuration.init(self)
    def contextMenuEvent(self, event):
        menu = QtGui.QMenu()
        action = QtGui.QAction('Change font/font size...', self)
        def f():
            old_font = self.font()
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
    def event(self, event):
        try:
            self._reset_timer()
        except:
            pass
        return super().event(event)
    def keyPressEvent(self, event):
        if event.key() in [QtCore.Qt.Key_Return, QtCore.Qt.Key_Enter] and not event.modifiers() & QtCore.Qt.ShiftModifier:
            number = self.textCursor().blockNumber()
            line = self.document().findBlockByLineNumber(number).text()
            if line.startswith('- '):
                self.insertPlainText('\n- ')
                return
        return super().keyPressEvent(event)
    def handle_close(self):
        if self.is_edited:
            print("Modified data discarded at close. (document '" + self.document_name + "')")
    def _handle_text_changed(self):
        if not self.is_edited:
            self.is_edited = True
            self._update_tab(self)
        self._update_toc()
    def read_file(self, file_name):
        print('read_file -', file_name)
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
    def show_position(self, position):
        self.moveCursor(QtGui.QTextCursor.End)
        cursor = self.textCursor()
        cursor.setPosition(position)
        self.setTextCursor(cursor)
    def write_file(self, file_name=''):
        if not file_name:
            if self.has_file:
                file_name = self.file_absolute_path
        print('write_file -', file_name)
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

class Browser(QtGui.QListWidget):
    def __init__(self, get_current_editor, open_tab, parent=None):
        super().__init__(parent)
        self._get_current_editor = get_current_editor
        self._open_tab = open_tab
        self.itemClicked.connect(self._handle_item_clicked)
        import configuration
        configuration.init(self)
    def _handle_item_clicked(self, item):
        if item.is_dummy:
            return
        if item.is_myself:
            return
        import os
        if item.is_parent:
            self._directory = os.path.dirname(self._directory)
            self._update_files()
            return
        if item.is_dir:
            self._directory = item.absolute_path
            self._update_files()
        if item.is_file:
            self._open_tab(item.absolute_path)
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
        print('browser._update_files() -', self._directory)
        self.clear()
        def get_new_item():
            item = QtGui.QListWidgetItem()
            item.is_dummy = False
            item.is_myself = False
            item.is_parent = False
            item.is_dir = False
            item.is_file = False
            return item
        item = get_new_item()
        item.is_dummy = True
        text = self._directory
        item.setText(text)
        self.addItem(item)
        indent = '    '
        item = get_new_item()
        item.is_myself = True
        item.setText(indent + '.')
        self.addItem(item)
        import os
        parent = os.path.dirname(self._directory)
        if not os.path.samefile(parent, self._directory):
            item = get_new_item()
            item.is_parent = True
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
            item = get_new_item()
            item.is_dir = True
            item.absolute_path = entry
            basename = os.path.basename(entry)
            item.setText(indent + basename + os.sep)
            self.addItem(item)
        for entry in files:
            item = get_new_item()
            item.is_file = True
            item.absolute_path = entry
            basename = os.path.basename(entry)
            stat = os.stat(entry)
            size = stat.st_size
            text = indent + basename + ' (' + str(size) + ')'
            if os.path.samefile(entry, self._path):
                text += ' --->'
            item.setText(text)
            self.addItem(item)

class TOC(QtGui.QListWidget):
    def __init__(self, get_current_editor, parent=None):
        super().__init__(parent)
        self._get_current_editor = get_current_editor
        self.itemClicked.connect(self._handle_item_clicked)
        import configuration
        configuration.init(self)
    def _handle_item_clicked(self, item):
        widget = self._get_current_editor()
        if widget is None:
            return
        widget.show_position(item.start)
        widget.setFocus()
    def update(self):
        widget = self._get_current_editor()
        if widget is None:
            self.clear()
            return
        text = widget.toPlainText()
        import re
        founds = []
        # for i, tag in enumerate(tags):
        for i in range(1, 7):
            tag = r'^' + r'#' * i + ' (.*)$'
            regex = re.compile(tag, flags=re.MULTILINE)
            for match in regex.finditer(text):
                founds.append((match.start(), match.end(), i, match.group(1)))
        founds.sort()
        counted = []
        self.total = len(text)
        for i in range(len(founds)):
            if i + 1 < len(founds):
                next = founds[i + 1][0]
            else:
                next = self.total
            length = next - founds[i][0]
            counted.append(founds[i] + (length, ))
        self.data = []
        for x in counted:
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
        for x in self.data:
            item = QtGui.QListWidgetItem()
            item.start = x['start']
            indent = '    ' * (x['level'] - 1)
            text = indent + x['string'] + ' (' + str(x['length']) + ')'
            item.setText(text)
            self.addItem(item)
        item = QtGui.QListWidgetItem()
        text = '(' + str(self.total) + ' characters)'
        item.setText(text)
        self.addItem(item)

def main():
    import sys
    app = QtGui.QApplication(sys.argv)
    print('Asking password.')
    dialog = PasswordDialog()
    result = dialog.exec_()
    if result == QtGui.QDialog.Accepted:
        print('User password temporary remembered.')
        window = MainWindow(dialog.password)
        window.show()
        sys.exit(app.exec_())
    else:
        print('Password input canceled.')

if __name__ == '__main__':
    main()
