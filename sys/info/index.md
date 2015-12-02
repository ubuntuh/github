# info

### 2015-12-02 Wed

- info コマンドには、デフォルトの検索ディレクトリがあるらしい。しかし、bash で echo $INFOPATH としても見られない。
- http://unix.stackexchange.com/questions/22329/gnu-texinfo-directory-search-method
- にて説明されているように、strings \`which info\` | grep /info とすれば見られる。
- 私の環境では以下のようになっているようだ。
    - /usr/local/info
    - /usr/info
    - /usr/local/lib/info
    - /usr/lib/info
    - /usr/local/gnu/info
    - /usr/local/gnu/lib/info
    - /usr/gnu/info
    - /usr/gnu/lib/info
    - /opt/gnu/info
    - /usr/share/info
    - /usr/share/lib/info
    - /usr/local/share/info
    - /usr/local/share/lib/info
    - /usr/gnu/lib/emacs/info
    - /usr/local/gnu/lib/emacs/info
    - /usr/local/lib/emacs/info
    - /usr/local/emacs/info
    - .
- なお、man ページの多くは /usr/share/man にあり、info ページの多くは /usr/share/info にある。
- info bash としても bash の man ページが表示されてしまう。web から bash の info ページはダウンロードできるので、それを用いることも考えられるが、どこに配置すべきかわからない。そもそも、多くの info ページは apt-get でインストールした際などにインストールされているので、手動で info ページをインストールするのは正しくない気がする。bash の info ページをインストールする正しい方法がわからない。info ページについての情報は、info という語が一般的すぎて、かなり検索しづらい。

