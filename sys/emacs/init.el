;; Add (load "~/github/sys/emacs/init.el") in ~/.emacs.d/init.el
;; ロードパスにパスを追加します。
(add-to-list 'load-path "~/github/sys/emacs/site-lisp")
;; ロードパスの追加が機能していることを確認するためにサンプルプログラムを読み込みます。正しく読み込めていれば、Alt+X helloworld とすると「hello, world」と出力されます。
;;(require 'helloworld)
(autoload 'helloworld "helloworld" nil t)

;; ポインタの位置を記憶して復元します。
;; 記憶するポインタ位置のデータはデフォルトでは ~/.emacs.d/places というファイルに記録されるようです。
(require 'saveplace)
(setq-default save-place t)
;; example.txt~ といったバックアップファイルを作りません。
(setq make-backup-files nil)
;; #example.txt# といったオートセーブファイルを作りません。
(setq auto-save-default nil)

;; タブ関係の設定をします。
;; 1 つのタブの幅は空白 4 つ分とします。
(setq default-tab-width 4)
(setq tab-stop-list '(4 8 12 16))
;; タブ文字ではなく空白でインデントをします。
(setq-default indent-tabs-mode nil)
;; 行頭で C-k を a 回押したら、行の内容だけでなく行末の改行も削除します。
(setq kill-whole-line t)
;; スクロール関係の設定をします。
(setq scroll-step 1)
(setq scroll-conservatively 10000)
;(setq auto-window-vscroll nil)
(setq scroll-margin 10)
(setq next-screen-context-lines 2)

;; ポインタを点滅させません。
(blink-cursor-mode 0)
;; ツールバーを非表示にします。
(tool-bar-mode 0)
;; メニューバーを非表示にします。
;; メニューには、追加した機能やそのキーバインドが表示されることもありますし、特に emacs に慣れないうちは表示しておいたほうが良さそうです。表示しないほうが美しいとは思います。
;;(menu-bar-mode 0)
;; なにやらスクロールバーが正常に描画されないのでいっそ消します。
(scroll-bar-mode -1)
;; スタート画面を表示しません。
(setq inhibit-startup-screen t)

;; 改行コードが LF であった場合に、モードラインに : ではなく (LF) と表示します。
(setq eol-mnemonic-unix "(LF)")
(setq eol-mnemonic-mac "(CR)")
(setq eol-mnemonic-dos "(CRLF)")
;; 対応する括弧を強調表示します。
(show-paren-mode 1)
;; 対応する括弧が画面内に収まっていない場合には括弧の内容を強調表示します。
(setq show-paren-style 'mixed)

(setq require-final-newline t)
(setq next-line-add-newlines nil)

;; ポインタのある行を強調表示します。
;; ターミナルで用いると不適当な色になることがあるようです。
;; ポインタのある行の色の表示がわかりにくくなってしまうことがあるようなので、使いません。
;;(global-hl-line-mode 1)
;; 行番号を表示します。
(global-linum-mode t)
;; 行番号の表示は、ターミナルだと見にくいようです。
;; 行番号の表示は変更できます。しかし右詰めにするのは簡単でないようです。
;;(setq linum-format 'dynamic)
(column-number-mode 1)
;; ホワイトスペースを表示します。
;; 何やら表示が乱れるので利用しません。
;;(global-whitespace-mode 1)
;;(setq whitespace-style '(face tabs tab-mark spaces space-mark newline newline-mark))

;; 背景を透過させます。
;; 背景のみならず文字などの前景を含めて全体が透過してしまうようです。しかし、透明度が低ければ大きな問題はないということで、そのような状態で使っている方は多くいるようです。
(set-frame-parameter nil 'alpha 85)
(add-to-list 'default-frame-alist '(alpha . 85))

;; カラーテーマを設定します。
;; gnome-terminal で使うと背景の透過が失われてしまうようです。
;; 以下の 14 種類のカラーテーマは、デフォルトで利用可能です。
;; /usr/share/emacs/24.5/etc/themes/
;;(load-theme 'adwaita t)
;;(load-theme 'deeper-blue t)
;;(load-theme 'dichromacy t)
;;(load-theme 'leuven t)
;;(load-theme 'light-blue t)
;;(load-theme 'manoj-dark t)
;;(load-theme 'misterioso t)
;;(load-theme 'tango t)
;;(load-theme 'tango-dark t)
;;(load-theme 'tsdh-dark t)
;;(load-theme 'tsdh-light t)
;;(load-theme 'wheatgrass t)
;;(load-theme 'whiteboard t)
;;(load-theme 'wombat t)
;; 以上はデフォルトで使用可能なカラーテーマでした。
(load-file "~/github/sys/emacs/site-lisp/manoj-dark2-theme.el")

;; ターミナルで起動した場合の色がおかしい気がする。
;; TERM=xterm-256color emacs -nw などとして起動すればよいという話題があるようだが、自分の環境ではそもそも変数 TERM は xterm-256color だし、export もされている。emacs 内で色数を見ても 500 以上表示される。
;; 逆に TERM=xterm emacs -nw とするとよいという話もある。しかしどちらにせよ私の環境では影響しないようだ。あと、TERM に使える値として、tty1 で使われている linux というのがあるが、関係なさそうである。
;; http://stackoverflow.com/questions/26120490/why-is-emacs-syntax-highlighting-in-gnome-terminal-affected-by-terminal-colour-t


;; デフォルトでは markdown 文書を扱えないので、広く使われている markdown-mode.el を利用して、扱えるようにします。markdown-mode.el は、キーワードを強調表示するのみならず、プレビューの表示など多くの機能を持っています。
;; なおそのためには、sudo apt-get install emacs-goodies-el などとして markdown-mode.el をインストールする必要があります。
(autoload 'markdown-mode "markdown-mode"
   "Major mode for editing Markdown files" t)
(add-to-list 'auto-mode-alist '("\\.md\\'" . markdown-mode))



;; 日本語入力プログラムである mozc に関する設定をします。
;; なんだかうまく動かないので使いません。
;; (require 'mozc)
;; (load-file "~/github/sys/emacs/site-lisp/mozc.el")
;; (set-language-environment "Japanese")
;; (setq default-input-method "japanese-mozc")
;; (setq mozc-candidate-style 'overlay)
;; (toggle-input-method)







