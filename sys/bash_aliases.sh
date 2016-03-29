#!/bin/bash
# 例えば ~/.bash_aliases において次の 2 行を書いてこのファイルを使う。
# export GIT=/media/tmp/NTFS/github
# . $GIT/sys/bash_aliases.sh
alias ls='ls --color=never'
alias ll='ls -alF --color=never'
alias la='ls -A --color=never'
alias l='ls -CF --color=never'
alias cp="cp --interactive --verbose"
alias mv="mv --interactive --verbose"
alias rm="rm --interactive --verbose"
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
export MANPATH=$GIT/sys/man:$MANPATH
# man コマンドを使用した際に、日本語で書かれたページのフォーマットが崩れないようにする。
export MANROFFOPT="-mja"
export INFOPATH=$GIT/sys/info:$INFOPATH
# http://misc.flogisoft.com/bash/tip_colors_and_formatting
# PS1='\[\e[92;1m\]\w\$\[\e[0m\] '
PS1='\[\e[92;1m\]$(echo ${PWD/$GIT/\$GIT})\$\[\e[0m\] '
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
 contest=$GIT/contest
    aizu=$GIT/contest/aizu
 atcoder=$GIT/contest/atcoder
    html=$GIT/html
      md=$GIT/md
    book=$GIT/md/book
   oscar=$GIT/md/lib/oscar
 thought=$GIT/md/thought
     src=$GIT/src
    bash=$GIT/src/bash
       c=$GIT/src/c
     clj=$GIT/src/clojure
halloway=$GIT/src/clojure/halloway
     cpp=$GIT/src/cpp
 haskell=$GIT/src/haskell
  python=$GIT/src/python
   sympy=$GIT/src/python/sympy
     sys=$GIT/sys
     tmp=$GIT/tmp
# 特定のファイルのパスをここで定義する。
   ejdic=$GIT/sys/ejdic-hand-utf8.txt
   edict=$GIT/sys/edict
html() {
	if [ $# -eq 0 ]; then
		ls "$GIT/sys/html"
	else
		if [ -e "$GIT/sys/html/$1.html" ]; then
			xdg-open "$GIT/sys/html/$1.html"
		elif [ -e "$GIT/sys/html/$1/index.html" ]; then
			xdg-open "$GIT/sys/html/$1/index.html"
		else
			echo "Not Found: $GIT/sys/html/$1.html"
			echo "Not Found: $GIT/sys/html/$1/index.html"
		fi
	fi
}
a() {
	./a.out "$@"
}
opn_args=
opn() {
	if [ $# -ne 0 ]; then
		opn_args="$@"
	fi
	echo xdg-open $opn_args
	xdg-open $opn_args
}
two_asm_args=
2asm() {
	if [ $# -ne 0 ]; then
		two_asm_args="$@"
	fi
	echo gcc -m32 -O0 -S -fno-asynchronous-unwind-tables $two_asm_args
	gcc -m32 -O0 -S -fno-asynchronous-unwind-tables $two_asm_args
}
asm_two_args=
asm2() {
	if [ $# -ne 0 ]; then
		asm_two_args="$@"
	fi
	echo gcc -m32 -O0 -g $asm_two_args
	gcc -m32 -O0 -g $asm_two_args
}
gcc_args=
c() {
	if [ $# -ne 0 ]; then
		gcc_args="$@"
	fi
	echo gcc $gcc_args
	gcc $gcc_args
}
gpp_args=
d() {
	if [ $# -ne 0 ]; then
		gpp_args="$@"
	fi
	echo g++ $gpp_args
	g++ $gpp_args
}
emacs_args=
e() {
	if [ $# -ne 0 ]; then
	emacs_args="$@"
	fi
	echo emacs --no-window-system $emacs_args
	emacs --no-window-system $emacs_args
}
ej() {
	grep "$*" $ejdic
}
je() {
	grep "$*" $edict
}
ggl() {
	xdg-open "https://www.google.com/search?q=$*"
}
ge() {
	xdg-open "https://www.google.co.jp/search?gl=US&hl=en&q=$*"
}
gj() {
	xdg-open "https://www.google.co.jp/search?gl=JP&hl=ja&q=$*"
}
ggli() {
	xdg-open "https://www.google.com/search?tbm=isch&q=$*"
}
nws() {
	xdg-open "https://news.google.com/?ned=us"
}
nwsja() {
	xdg-open "https://news.google.com/?ned=jp"
}
pron() {
	$GIT/sys/python/getWeblioPronunciation.py "$*"
}
yt() {
	xdg-open "https://www.youtube.com/results?search_query=$*"
}
wp() {
	xdg-open "https://en.wikipedia.org/wiki/$*"
}
weblio() {
	xdg-open "http://ejje.weblio.jp/content/$*"
}
