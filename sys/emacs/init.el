;; Add (load "~/github/sys/emacs/init.el") in ~/.emacs.d/init.el
;; ロードパスにパスを追加します。
(add-to-list 'load-path "~/github/sys/emacs/site-lisp")
;; カラーテーマを設定します。
;; gnome-terminal で使うと背景の透過が失われてしまうようです。
;;(load-theme 'manoj-dark t)
;; メニューバーを非表示にします。
(menu-bar-mode 0)
;; ツールバーを非表示にします。
(tool-bar-mode 0)
;; example.txt~ といったバックアップファイルを作りません。
(setq make-backup-files nil)
;; #example.txt# といったオートセーブファイルを作りません。
(setq auto-save-default nil)

;; スタートアップスクリーンを表示しません。
(setq inhibit-startup-screen t)

;;(global-whitespace-mode 1)

(setq default-tab-width 4)
(setq tab-stop-list '(4 8 12 16))
(setq-default indent-tabs-mode nil)

(setq eol-mnemonic-unix "(LF)")
;; 対応する括弧を強調表示します。
(show-paren-mode 1)
;; 対応する括弧が画面内に収まっていない場合には括弧の内容を強調表示します。
(setq show-paren-style 'mixed)

;; ポインタの位置を記憶して復元します。
(require 'saveplace)
(setq-default save-place t)

;; 行頭で C-k を a 回押したら、行の内容だけでなく行末の改行も削除します。
(setq kill-whole-line t)


(setq require-final-newline t)


(setq next-line-add-newlines nil)

;; ポインタのある行を強調表示します。
;; ターミナルで用いると不適当な色になることがあるようです。
;;(global-hl-line-mode 1)
;; 行番号を表示します。
(global-linum-mode t)
;;(setq linum-format 'dynamic)

;;(line-number-mode 1)
(column-number-mode 1)
;;(global-whitespace-mode 1)

(setq whitespace-style '(face tabs tab-mark spaces space-mark newline newline-mark))
