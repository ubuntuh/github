HISTSIZE=-1
HISTFILESIZE=-1
# http://misc.flogisoft.com/bash/tip_colors_and_formatting
PS1='\[\e[92;1m\]\w\$\[\e[0m\] '
PS2='\[\e[92;1m\]>\[\e[0m\] '
doc=~/Documents
dl=~/Downloads
pr=~/Programming
git=~/github
md=$git/md
src=$git/src
sys=$git/sys
info=$sys/info
oscar=$md/lib/oscar
bash=$src/bash
c=$src/c
cpp=$src/cpp
clj=$src/clojure
halloway=$clj/halloway
ejdic=$sys/ejdic-hand-utf8.txt
edict=$sys/edict
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

