#!/usr/bin/env python3
# -*- coding: utf-8 -*-
u"与えられた英単語の発音をオンライン辞書である「Weblio」で調べて返すプログラムである。"
from html.parser import HTMLParser
import sys
import urllib.request

class Parser(HTMLParser):
    u"""HTML データを与えられて、目的の部分のみを変数 datas に蓄えるオブジェクトである。"""
    def __init__(self):
        HTMLParser.__init__(self)
        self.datas = []
        self.inTarget = False
        self.nest = 0

    def handle_starttag(self, tag, attrs):
        if tag == 'span' and (u'class', u'phoneticEjjeDesc') in attrs:
            self.inTarget = True
            self.datas.append("")
        elif self.inTarget:
            self.nest = self.nest + 1

    def handle_endtag(self, tag):
        if self.inTarget:
            if self.nest > 0:
                self.nest = self.nest - 1
            else:
                self.inTarget = False

    def handle_data(self, data):
        if self.inTarget:
            self.datas[-1] = self.datas[-1] + data

def main():
    argv = sys.argv
    isVerbose = False
    if len(argv) >= 2 and argv[1] == "-v":
        isVerbose = True
        del argv[1]
    if len(argv) == 1:
        print('Error: No arguments.')
        return
    joined = ' '.join(argv[1:])
    url = 'http://ejje.weblio.jp/content/' + joined
    response = urllib.request.urlopen(url)
    encoding = response.headers.get_param('charset')
    html = response.read()
    response.close()
    decoded = html.decode(encoding)
    if (isVerbose):
        if (decoded[-1] == "\n"):
            print(decoded, end="")
        else:
            print(decoded)
        print("HTML len = " + str(len(decoded)))
        print("HTML numLines = " + str(decoded.count("\n")))
    parser = Parser()
    parser.feed(decoded)
    parser.close()
    datas = parser.datas
    if not datas:
        print('Failed.')
    else:
        for data in datas:
            print(data)

if __name__ == '__main__':
    main()
