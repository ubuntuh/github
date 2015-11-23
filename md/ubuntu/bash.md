# bash

- gnome-terminal とやらと bash とやらの違いが不明である。
- Ctrl+Alt+T で terminal を開ける。

#### .bash_aliases

- terminal 起動時に自動的に実行してほしいコマンドは、~/.bash_aliases に書く。
    - terminal は起動時に ~/.bashrc を読むが、これが ~/.bash_aliases を読み込んでくれる。可能なら .bashrc を改変するのではなく .bash_aliases を作って編集すべきことは、その ~/.bashrc に買いてある。
- 変数の定義は、`export example=~/example/example` などとする。使う時は $ をつけて `cd $example` などとする。
    - 変数名は大文字が推奨されているようだが小文字も使われているようである。
- プロンプトの変更は `PS1='$ '` などとする。
    - デフォルトでの $PS1 の値は、`\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ ` であった。
    - 例えば `PS1='\[\033[7;37m\]\w\[\033[00m\]'`とすると、少しシンプルになる。
