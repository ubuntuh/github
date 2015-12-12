#!/bin/bash
# ~/.bash_aliases などから「. ~/github/sys/bash_aliases.sh」などとして呼び出すことができる。
HISTSIZE=-1
HISTFILESIZE=-1
export MANPATH=~/github/sys/man:$MANPATH
export INFOPATH=~/github/sys/info:$INFOPATH
# http://misc.flogisoft.com/bash/tip_colors_and_formatting
PS1='\[\e[92;1m\]\w\$\[\e[0m\] '
PS2='\[\e[92;1m\]>\[\e[0m\] '
title='TITLE'
# ターミナルの制御文字を使ってタイトルを変更します。
echo -e "\e]0;" $(date +%H:%M:%S) "\a"
# プロンプトを表示するたびに命令を実行することもできます。
# PROMPT_COMMAND='echo -e "\e]0;" $(date +%H:%M:%S) "\a"'
     doc=~/Documents
      dl=~/Downloads
      pr=~/Programming
     git=~/github
      md=~/github/md
    book=~/github/md/book
   oscar=~/github/md/lib/oscar
 thought=~/github/md/thought
     src=~/github/src
    bash=~/github/src/bash
       c=~/github/src/c
     clj=~/github/src/clojure
halloway=~/github/src/clojure/halloway
     cpp=~/github/src/cpp
  python=~/github/src/python
     sys=~/github/sys
   ejdic=~/github/sys/ejdic-hand-utf8.txt
   edict=~/github/sys/edict
html() {
    if [ $# -eq 0 ]
    then
        ls "$git/sys/html"
    else
        xdg-open "$git/sys/html/$1.html"
    fi
}
a() {
    ./a.out "$@"
}
ej() {
    grep "$1" $ejdic
}
je() {
    grep "$1" $edict
}
google() {
    xdg-open "https://www.google.com/search?q=$*"
}
google-en() {
    xdg-open "https://www.google.co.jp/search?gl=US&hl=en&q=$*"
}
google-i() {
    xdg-open "https://www.google.com/search?tbm=isch&q=$*"
}
news() {
    xdg-open "https://news.google.com/?ned=us"
}
youtube() {
    xdg-open "https://www.youtube.com/results?search_query=$*"
}
wikipedia() {
    xdg-open "https://en.wikipedia.org/wiki/$1"
}
weblio() {
    xdg-open "http://ejje.weblio.jp/content/$1"
}

