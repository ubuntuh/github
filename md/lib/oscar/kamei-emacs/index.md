# プログラマに捧げる GNU Emacs ガイドブック

- by 亀井信義 (Nobuyoshi Kamei), 舘野信行 (Nobuyuki Tateno)
- １９９３年１２月２５日初版第１刷

<!-- -->

- p. 6 - 表示して改行すると、もう 2 度と前の行に戻れないというテレタイプ端末だったに違いない。
- Unix では、この ed に幾つかの機能を追加した ex というものがある...
- さらに、ex にスクリーンモードを付けた、vi という名前のエディタができた。
- したがって、すべての行について、テキストをちょこまかと直すような作業は、非常にやりにくい。たとえば次のように、モード切り替えというのを延々と繰り返すことになる。
- p. 7 - このため私個人の独断では、vi はスクリーンモードの付いた、ラインエディタに過ぎない。
- p. 10 - 快適な環境というのは大事である。人間の精神状態は少なからず環境に左右されるのだから。
- vi には両手をフルに使うという感覚がない。
- p. 11 - 東京 GNU テクニカル・セミナー 1992 年 12 月 2 日（水） 東京 六本木 国際文化会館 - Stallman の講演題目: プロジェクト GNU---過去、現在、そして将来
- p. 12 - MIT Lisp System
- p. 13 - この GNU プロジェクトを始めるにあたって、Stallman は、MIT の AI ラボを辞職したという。理由は、Stallman の GNU 活動を妨げるための法律的根拠を、MIT にまったく与えないようにするためである。Stallman はまず始めに独りで作業を開始したとうい。そうして出来上がった最初の GNU の製品が、GNU Emacs であった。
- p. 14 - 筆者もこの話を聞いてたいへん驚いたのだが、Stallman は、FSF からお金をもらったことは一度もない (never) という。自分に費やすような無駄な使い方をするよりも、その金で誰か他の人を FSF に雇った方がいい、と考えるのだそうだ。筆者のような凡人は、ただただ、恐れ入るばかりである。
- p. 32 - C-h t help-with-tutorial
- p. 33 - C-x C-f find-file
- C-x C-r find-file-read-only
- C-x C-q toggle-read-only
- C-x i insert-file
- C-x C-s save-buffer
- C-x C-w write-file
- C-x s save-some-buffers
- set-visited-file-name
- p. 34 - M-x set-visited-file-name
- C-f forward-char
- C-b backward-char
- M-f forward-word
- M-b backward-word
- C-p previous-line
- C-n next-line
- C-a beginning-of-line
- C-e end-of-line
- C-v scroll-up
- M-v scroll-down
- M-r move-to-window-line
- M-< beginning-of-buffer
- C-l recenter
- p. 35 - M-5 C-f
- C-u 5 C-f
- C-x = what-cursor-position
- M-x what-line
- C-g keyboard-quit
- C-_ undo
- C-x u advertised-undo
- p. 36 - M-5 C-x u
- C-g を入力するとアンドゥの方向が変わる。
- p. 37 - C-q quoted-insert
- C-q C-l
- C-q 123
- M-x overwrite-mode
- p. 38 - C-o open-line
- M-C-o split-line
- C-x C-o delete-blank-lines
- M-\ delete-horizontal-space
- DEL delete-backward-char
- C-d delete-char
- M-DEL backward-kill-word
- M-d kill-word
- C-k kill-line
- C-y yank
- p. 39 - C-@ set-mark-command
- M-@ mark-word
- C-x h mark-whole-buffer
- C-w kill-region
- M-w copy-region-as-kill
- M-= count-lines-region
- p. 40 - capitalize-region
- C-x C-l downcase-region
- C-x C-u upcase-region
- M-c capitalize-word
- M-l downcase-word
- M-u upcase-word
- C-s isearch-forward
- C-r isearch-backward
- p. 41 - M-% query-replace
- replace-string

## 3. 基本概念

- p. 51 - C-f forward-char
- C-b backward-char
- goto-char
- p. 52 - M-f forward-word
- M-b backward-word
- C-n next-line
- C-p previous-line
- C-a beginning-of-line
- C-e end-of-line
- goto-line
- C-x C-n set-goal-column
- track-eol
- C-x = what-cursor-position
- what-line
- what-page
- p. 54 - C-@ set-mark-command
- mark-ring
- C-u C-@
- mark-ring-max
- M-< beginning-of-buffer
- C-s isearch-forward
- C-@ set-mark-command
- M-@ mark-word
- M-C-@ mark-sexp
- M-h mark-paragraph
- M-C-h mark-defun
- p. 56 - C-x h mark-whole-buffer
- C-x C-x exchange-point-and-mark
- C-x 2 split-window-vertically
- C-x 5 split-window-horizontally
- C-x 0 delete-window
- C-x 1 delete-other-window
- delete-windows-on
- C-x ^ enlarge-window
- shrink-window
- C-x { shrink-window-horizontally
- C-x } enlarge-window-horizontally
- p. 57 - C-l recenter
- M-r move-to-window-line
- C-x o other-window
- C-v scroll-up
- M-v scroll-down
- M-C-v scroll-other-window
- C-x < scroll-left
- C-x > scroll-right
- next-screen-context-lines
- p. 59 - C-x b switch-to-buffer
- C-x 4 b switch-to-buffer-other-window
- p. 60 - C-x k kill-buffer
- kill-some-uffers
- C-x C-q toggle-read-only
- M-~ not-modified
- p. 61 - rename-buffer
- C-x C-b list-buffers
- buffer-menu














