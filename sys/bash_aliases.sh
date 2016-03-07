#!/bin/bash
# ~/.bash_aliases などから「. ~/github/sys/bash_aliases.sh」などとして呼び出すことができる。
alias cp="cp --interactive --verbose"
alias mv="mv --interactive --verbose"
alias rm="rm --interactive --verbose"
alias open="xdg-open"
# 連続して同一のコマンドが実行された場合にコマンド履歴に記録しない、空白で始まるコマンドは記録しない、といった機能を無効にする。
unset HISTCONTROL
# コマンド履歴が記録されるファイルは通常 ~/.bash_history だが、変更する。
# 変数 HISTFILESIZE などを用いて、コマンド履歴の記録量を普通より大きくあるいは無制限に大きくしたいが、デフォルトの状態だと ~/.bashrc などでの変数 HISTSIZE などの設定によって、溢れたデータが削除されるようだ。その .bashrc ファイルなどを改変しても改善できるが、環境の再構築を簡単にするため、独自な記録ファイルにここで切り替えることによって記録の破壊を避ける。
export HISTFILE=~/.bash_history2
# コマンド履歴を無制限に大きく記録するための設定をする。
# なお同じことを unset でやっても機能せず、記録は破壊される。
export HISTFILESIZE=
export HISTSIZE=
# コマンド履歴に日時も記録する。また、history コマンドを使用した際にその日時を整形表示する。フォーマットは strftime 形式。
# ただしそもそも、複数のターミナルを使った場合それぞれ終了時に書き込むため、履歴の日時は必ずしも整列されない。
export HISTTIMEFORMAT='(%F %a %T) '
# less コマンドのオプションを設定する。
export LESS='-M +Gg'
export MANPATH=~/github/sys/man:$MANPATH
export INFOPATH=~/github/sys/info:$INFOPATH
# http://misc.flogisoft.com/bash/tip_colors_and_formatting
PS1='\[\e[92;1m\]\w\$\[\e[0m\] '
PS2='\[\e[92;1m\]>\[\e[0m\] '
title='TITLE'
# ターミナルの制御文字を使ってタイトルを変更する。
echo -e "\e]0;" $(date +"%a %H:%M:%S") "\a"
# プロンプトを表示するたびに命令を実行することもできる。
# PROMPT_COMMAND='echo -e "\e]0;" $(date +%H:%M:%S) "\a"'
# 変数を定義して、頻繁に用いるディレクトリに直接移動できるようにする。
     doc=~/Documents
      dl=~/Downloads
      pr=~/Programming
     git=~/github
 contest=~/github/contest
    aizu=~/github/contest/aizu
 atcoder=~/github/contest/atcoder
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
 haskell=~/github/src/haskell
  python=~/github/src/python
     sys=~/github/sys
# 特定のファイルのパスをここで定義する。
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
two_asm_args=
2asm() {
    if [ $# -ne 0 ]; then
	two_asm_args=$*
    fi
    echo gcc -m32 -O0 -S -fno-asynchronous-unwind-tables $two_asm_args
    gcc -m32 -O0 -S -fno-asynchronous-unwind-tables $two_asm_args
}
asm_two_args=
asm2() {
    if [ $# -ne 0 ]; then
	asm_two_args=$*
    fi
    echo gcc -m32 -O0 -g $asm_two_args
    gcc -m32 -O0 -g $asm_two_args
}
gcc_args=
c() {
    if [ $# -ne 0 ]; then
        gcc_args=$*
    fi
    echo gcc $gcc_args    
    gcc $gcc_args    
}
gpp_args=
d() {
    if [ $# -ne 0 ]; then
        gpp_args=$*
    fi
    echo g++ $gpp_args    
    g++ $gpp_args    
}
emacs_args=
e() {
    if [ $# -ne 0 ]; then
        emacs_args=$*
    fi
    echo emacs --no-window-system $emacs_args
    emacs --no-window-system $emacs_args
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

