#!/usr/bin/env python
# -*- coding: utf-8 -*-
u"与えられた英単語の発音をオンライン辞書である「Weblio」で調べて返すプログラムである。"
from HTMLParser import HTMLParser
import sys
import urllib2

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
    if len(argv) == 1:
        print('Error: No arguments.')
        return
    joined = ' '.join(argv[1:])
    print("Input = " + joined)
    url = 'http://ejje.weblio.jp/content/' + joined
    response = urllib2.urlopen(url)
    encoding = response.headers.getparam('charset')
    html = response.read()
    response.close()
    decoded = html.decode(encoding)
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
