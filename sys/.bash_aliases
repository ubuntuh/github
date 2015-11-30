HISTSIZE=-1
HISTFILESIZE=-1
# http://misc.flogisoft.com/bash/tip_colors_and_formatting
PS1='\[\e[92;1m\]\w\$\[\e[0m\] '
PS2='\[\e[92;1m\]>\[\e[0m\] '
     doc=~/Documents
      dl=~/Downloads
      pr=~/Programming
     git=~/github
      md=~/github/md
    book=~/github/md/book
   oscar=~/github/md/lib/oscar
     src=~/github/src
    bash=~/github/src/bash
       c=~/github/src/c
     clj=~/github/src/clojure
halloway=~/github/src/clojure/halloway
     cpp=~/github/src/cpp
     sys=~/github/sys
   ejdic=~/github/sys/ejdic-hand-utf8.txt
   edict=~/github/sys/edict
function a() {
    ./a.out "$@"
}
function ej() {
    grep "$1" $ejdic
}
function je() {
    grep "$1" $edict
}
function google() {
    xdg-open "https://www.google.com/search?q=$1"
}
function wikipedia() {
    xdg-open "https://en.wikipedia.org/wiki/$1"
}
function weblio() {
    xdg-open "http://ejje.weblio.jp/content/$1"
}

