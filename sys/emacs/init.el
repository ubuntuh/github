;; Add (load (concat (getenv "GIT") "/sys/emacs/init.el")) to ~/.emacs.d/init.el
(setq inhibit-startup-screen t) ; スタート画面を表示しません。
(add-to-list 'load-path (concat (getenv "GIT") "/sys/emacs/site-lisp")) ; ロードパスにパスを追加します。
(autoload 'helloworld "helloworld" nil t) ; ロードパスの追加が機能していることを確認するためにサンプルプログラムを読み込みます。正しく読み込めていれば、Alt+X helloworld とすると「hello, world」と出力されます。
(require 'saveplace)
(setq-default save-place t) ; ポイントの位置を記憶して復元します。記憶するポイント位置のデータはデフォルトでは ~/.emacs.d/places というファイルに記録されるようです。
(setq make-backup-files nil) ; example.txt~ といったバックアップファイルを作りません。
(setq auto-save-default nil) ; #example.txt# といったオートセーブファイルを作りません。
(setq kill-whole-line t) ; 行頭で C-k を 1 回押したら、行の内容だけでなく行末の改行も削除します。
(blink-cursor-mode 0) ; ポイントを点滅させません。
;; 1 つもファイルを開いていない時に表示されるメッセージを消します。
(setq initial-scratch-message nil)

(setq eol-mnemonic-unix "(LF)") ; 改行コードが LF であった場合に、モードラインに : ではなく (LF) と表示します。
(setq eol-mnemonic-mac "(CR)")
(setq eol-mnemonic-dos "(CRLF)")

(setq show-paren-delay 0) ; 以下で対応する括弧を強調表示する際、デフォルトでは僅かに遅延させますが、その遅延をしないようにします。
(show-paren-mode 1) ; 対応する括弧を強調表示します。
;; (setq show-paren-style 'mixed) ; 対応する括弧が画面内に収まっていない場合には括弧の内容全体を強調表示するようにもできます。

;; ファイル末尾に自動的に改行を追加します。
;;(setq require-final-newline t)
;; (global-hl-line-mode 1) ; ポイントのある行を強調表示することができます。
(global-linum-mode t) ; 行番号を表示します。
;; 行番号の表示は変更できます。しかし右詰めにするのは簡単でないようです。
;;(setq linum-format 'dynamic)
(column-number-mode 1)

;; (global-whitespace-mode 1) ; ホワイトスペースを表示することができます。しかし何やら表示が乱れるので利用しません。
;; (setq whitespace-style '(face tabs tab-mark spaces space-mark newline newline-mark))

;; 背景を透過させます。背景のみならず文字などの前景を含めて全体が透過してしまうようです。しかし、透明度が低ければ大きな問題はないということで、そのような状態で使っている方は多くいるようです。
(set-frame-parameter nil 'alpha 85)
(add-to-list 'default-frame-alist '(alpha . 85))

(global-set-key "\C-h" 'delete-backward-char)
(setq default-tab-width 8) ; 1 つのタブの幅は空白 8 つ分とします。
(setq tab-stop-list '(8 16 24 32 40 48 56 64))
;; (setq-default indent-tabs-mode nil) ; タブ文字ではなく空白文字でインデントをすることもできます。
(setq-default indent-tabs-mode t)

(require 'fill-column-indicator) ; 80 文字の位置を表示します。
(setq fci-rule-column 80) ; デフォルトの表示位置は必ずしも 80 文字ではないので 80 文字にします。
(setq fci-handle-truncate-lines nil) ; fill-column-indicator.el が、truncate-lines を t にすることをやめさせます。
(setq fci-handle-line-move-visual nil) ; fill-column-indicator.el が、line-move-visual を nil にすることをやめさせます。

(add-hook 'haskell-mode-hook 'turn-on-haskell-doc-mode)
(add-hook 'haskell-mode-hook 'turn-on-haskell-indentation)

;; デフォルトでは markdown 文書を扱えないので、広く使われている markdown-mode.el を利用して、扱えるようにします。markdown-mode.el は、キーワードを強調表示するのみならず、プレビューの表示など多くの機能を持っています。
;; なおそのためには、sudo apt-get install emacs-goodies-el などとして markdown-mode.el をインストールする必要があります。
;; markdown-mode で、リストを記述する際には、改行の際に M-RET とすることが便利です。しかしこれは emacs -nw では使えないようだ。
;; emacs -nw で markdown で項目を折りたたむには、Tab ではなく Shift+Tab を押せばいい。Shift+Tab は backtab というものであるようである。
(autoload 'markdown-mode "markdown-mode"
   "Major mode for editing Markdown files" t)
(add-to-list 'auto-mode-alist '("\\.md\\'" . markdown-mode))
(setq markdown-indent-on-enter nil) ; 改行をした時に行末の空白が削除されることを避けます。

(if window-system
  (progn
    (tool-bar-mode 0) ; ツールバーを非表示にします。
    (scroll-bar-mode -1) ; なにやらスクロールバーが正常に描画されないのでいっそ消します。
    (setq x-select-enable-clipboard t)
    (load-file (concat (getenv "GIT") "/sys/emacs/site-lisp/manoj-dark2-theme.el"))
    (add-to-list 'default-frame-alist '(width . 69)) ; ウィンドウの幅を設定します。
    (add-to-list 'default-frame-alist '(height . 40))
    ;; (set-frame-size (selected-frame) 69 40))
    )
  (progn
    (menu-bar-mode 0) ; メニューバーを非表示にします。
    ;; 色の設定をします。
    ;; 最も基本的な約 16 色については、色名がわかりやすいので、これを重視して使ってしまうことにします。
    ;; M-x list-colors-display
    ;; (set-face-background 'default "color-16")
    (set-face-foreground 'default "brightwhite")
    (set-face-background 'mode-line "color-238")
    (set-face-foreground 'mode-line "color-16")
    (set-face-foreground 'font-lock-builtin-face "brightcyan")
    (set-face-foreground 'font-lock-constant-face "brightblue")
    (set-face-foreground 'font-lock-preprocessor-face "brightblue")
    (set-face-foreground 'font-lock-comment-face "brightmagenta")
    (set-face-foreground 'font-lock-function-name-face "brightgreen")
    (set-face-foreground 'font-lock-keyword-face "brightcyan")
    (set-face-foreground 'font-lock-string-face "brightblue")
    (set-face-foreground 'font-lock-type-face "brightblue")
    (set-face-foreground 'font-lock-variable-name-face "brightgreen")
    (set-face-foreground 'linum "magenta")
    (set-face-background 'show-paren-match-face "color-16")
    (set-face-foreground 'show-paren-match-face "brightwhite")
    ;; (setq hl-line-face 'underline)
    (add-hook 'c-mode-hook
	      '(lambda ()
		 (progn
		   (c-set-style "linux")
		   (setq indent-tabs-mode t) ; インデントにタブを使います。
		   (setq c-basic-offset 8)
		   (global-set-key (kbd "DEL") 'delete-backward-char)
		   (define-key c-mode-map (kbd "DEL") 'delete-backward-char)
		   (fci-mode 1)
		   )
		 )
	      )
    (add-hook 'c++-mode-hook
	      '(lambda ()
		 (progn
		   (c-set-style "linux")
		   (setq indent-tabs-mode t) ; インデントにタブを使います。
		   (setq c-basic-offset 8)
		   (global-set-key (kbd "DEL") 'delete-backward-char)
		   (define-key c-mode-map (kbd "DEL") 'delete-backward-char)
		   (fci-mode 1)
		   (setq c-hungry-delete-key t)
		   (setq c-tab-always-indent nil)
		   ;; (setq c-tab-always-indent nil) ; ポイントが行頭にない際は、インデントのためではなくタブを入力するためにタブキーを使うこともできます。
		   )
		 )
	      )
    (add-hook 'emacs-lisp-mode-hook
	      (lambda ()
		(progn
		  (setq indent-tabs-mode t) ; インデントにタブを使います。
		  (fci-mode 1) ; fill-column-indicator.el の機能を有効にします。
		  ;; (setq lisp-indent-offset 2)
		  )
		)
	      )
    (add-hook 'graphviz-dot-mode
	      (lambda ()
		(progn
		  
		  )
		)
	      )
    (add-hook 'sh-mode-hook
	      (lambda ()
		(progn
		  (setq sh-basic-offset 8)
		  (setq sh-indentation 8)
		  )
		)
	      )
    )
  )

;; emacs のバージョン 24.4 から electric-indent-mode がデフォルトでオンになった。
;; emacs では、改行時の動作として 3 つの関数がある。newline、newline-and-indent、reindent-then-newline-and-indent である。動作は名前が示す通りだが、reindent とは、現在の行の行頭のインデントを調整しなおすことである。
;; electric-indent-mode は、このうち、reindent-then-newline-and-indent の動作をするようである。
;; この reindent が意図と異なる動作をすると非常に煩わしいので、reindent というものは好ましくないと思われる。
;; そのため、その動作をしてしまう electric-indent-mode はオフでいい。
;; (electric-indent-mode -1)
;; newline-and-indent の動作は、デフォルトで C-j で可能である。
;; 一方で、electric-indent-mode をオフにした場合、普通にエンターキーを押したのでは、単に newline の動作になるようである。C-j のように、newline-and-indent の動作をした方が、一般的なテキストエディタとの関係で自然だろう。
;; 以下のように設定することで、エンターキーで newline-and-indent ができるようになるようだ。
;; (global-set-key "\C-m" 'newline-and-indent)

;; スクロール関係の設定をします。
;;(setq scroll-step 1)
;;(setq scroll-conservatively 10000)
;;(setq auto-window-vscroll nil)
;;(setq scroll-margin 10)
;;(setq next-screen-context-lines 2)

;; (require 'server)
;; (unless (server-running-p)
;;   (server-start)
;;   )

;; (setq explicit-shell-file-name "/bin/bash")
;; (setq shell-file-name "/bin/bash")

;; (desktop-save-mode 1)
;; メモ。can't guess python-indent-offset
;; いわゆる「最近使ったファイル」に関する機能を有効にします。
;; (require 'recentf)
;; (recentf-mode 1)

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

;; ターミナルで起動した場合の色がおかしい気がする。
;; TERM=xterm-256color emacs -nw などとして起動すればよいという話題があるようだが、自分の環境ではそもそも変数 TERM は xterm-256color だし、export もされている。emacs 内で色数を見ても 500 以上表示される。
;; 逆に TERM=xterm emacs -nw とするとよいという話もある。しかしどちらにせよ私の環境では影響しないようだ。あと、TERM に使える値として、tty1 で使われている linux というのがあるが、関係なさそうである。
;; http://stackoverflow.com/questions/26120490/why-is-emacs-syntax-highlighting-in-gnome-terminal-affected-by-terminal-colour-t

;; 矢印キーや Delete キーを無効にし、キーバインドに慣れる。
;; しかし、キーバインドで移動していると、Ctrl キーが緩んだ時に文字を入力してしまうのが煩わしい。
;; http://danamlund.dk/emacs/no-easy-keys.html
;; http://superuser.com/questions/437953/disable-arrow-keys-in-emacs
;;(require 'no-easy-keys)
;;(no-easy-keys 1)

;; 日本語入力プログラムである mozc に関する設定をします。
;; なんだかうまく動かないので使いません。
;; (require 'mozc)
;; (load-file "~/github/sys/emacs/site-lisp/mozc.el")
;; (set-language-environment "Japanese")
;; (setq default-input-method "japanese-mozc")
;; (setq mozc-candidate-style 'overlay)
;; (toggle-input-method)
