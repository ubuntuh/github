set autoindent
" 新たにタブキーが押された際、タブ文字ではなく（複数の）空白文字を入力します。
" タブ文字を入力したい場合には、Ctrl+V, Tab で入力できます。
set expandtab
" 空白文字などを可視化します。
set list
" 空白文字などの表示方法を設定します。
" trail は、行末の空白文字を意味します。
set listchars=eol:$,extends:>,nbsp:%,precedes:<,space:·,tab:>-,trail:~
" 行数を表示します。
set number
set shellcmdflag=-ic
" インデントに用いられる空白文字の数を設定します。
set shiftwidth=4
set showcmd
set smartindent
" 行頭の端数なインデントにおいてタブキーを入力した際、端数にならないようにします。
set smarttab
" 指定した数の空白文字を一つのタブ文字のように操作します。バックスペースキーについて有効です。
set softtabstop=4
" タブ文字がいくつの空白文字として表示されるか設定します。
set tabstop=4

