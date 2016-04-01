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
        self.in_target = False
        self.nest = 0

    def handle_starttag(self, tag, attrs):
        if tag == "span" and (u"class", u"phoneticEjjeDesc") in attrs:
            self.in_target = True
            self.datas.append("")
        elif self.in_target:
            self.nest = self.nest + 1

    def handle_endtag(self, tag):
        if self.in_target:
            if self.nest > 0:
                self.nest = self.nest - 1
            else:
                self.in_target = False

    def handle_data(self, data):
        if self.in_target:
            self.datas[-1] = self.datas[-1] + data

def main():
    argv = sys.argv
    is_verbose = False
    if len(argv) >= 2 and argv[1] == "-v":
        is_verbose = True
        del argv[1]
    if len(argv) == 1:
        print("Error: No arguments.")
        return
    joined = " ".join(argv[1:])
    url = "http://ejje.weblio.jp/content/" + joined
    with urllib.request.urlopen(url) as response:
        html_bytes = response.read()
    encoding = response.headers.get_param("charset")
    html_string = html_bytes.decode(encoding)
    if (is_verbose):
        if (html_string[-1] == "\n"):
            print(html_string, end="")
        else:
            print(html_string)
        print("HTML len = " + str(len(html_string)))
        print("HTML num_lines = " + str(html_string.count("\n")))
    parser = Parser()
    parser.feed(html_string)
    parser.close()
    datas = parser.datas
    if not datas:
        print("Failed.")
    else:
        for data in datas:
            print(data)

if __name__ == "__main__":
    main()
