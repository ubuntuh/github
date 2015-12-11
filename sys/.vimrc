" 「~/.vimrc」などから「so ~/github/sys/.vimrc」などとして呼び出すことができる。

" 論理行でカクカクスクロールするのをやめさせる方法はないようです。
" http://stackoverflow.com/questions/8369021/in-vim-how-to-scroll-continuously-by-screen-lines-when-wrapping-is-enabled

" 表示行で移動しやすくします。
noremap j gj
noremap k gk
noremap <Down>  gj
noremap <Up> gk
noremap gj j
noremap k gk
set ambiwidth=double
set autoindent
" 行全体が表示できなくても一部を表示します。
set display+=lastline
" 新たにタブキーが押された際、タブ文字ではなく（複数の）空白文字を入力します。
" タブ文字を入力したい場合には、Ctrl+V, Tab で入力できます。
set expandtab
" status line を常に表示します。
set laststatus=2
" 空白文字などを可視化します。
set list
" 空白文字などの表示方法を設定します。double width になる文字を指定すると ambiwidth=double と衝突してエラーになります。
" space は、空白文字を意味します。
" trail は、行末の空白文字を意味します。
set listchars=eol:$,extends:>,nbsp:%,precedes:<,tab:>-,trail:~
" 行数を表示します。
set number
set scrolloff=999
set shellcmdflag=-ic
" インデントに用いられる空白文字の数を設定します。
set shiftwidth=4
set showcmd
set smartindent
" 行頭の端数なインデントにおいてタブキーを入力した際、端数にならないようにします。
set smarttab
" 指定した数の空白文字を一つのタブ文字のように操作します。バックスペースキーについて有効です。
set softtabstop=4
set statusline=%F%M%=L%l/%L\ 0x%04B
" タブ文字がいくつの空白文字として表示されるか設定します。
set tabstop=4

