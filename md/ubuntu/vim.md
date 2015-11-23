# Vim

- ヴィム。Unix 系 OS で最も人気のあるテキストエディタ。
    - vim と emacs が人気だが、vim の方が比較的簡単。
    - 1976 年に Bill Joy (1954-) が作った vi を Bram Moolenaar (1961-) が改良して 1991 年に Vim を作った。
- GUI なテキストエディタと異なり、多くのコマンドを覚えていく必要がある。
    - それが割に合うかどうかは、状況によるだろう。
- terminal で `vimtutor` と入力すればチュートリアルを受けられる。ただし練習の過程で別途ファイルを作る場面が含まれる。
- 詳しい説明を読みたければ、vim の中で `:help` と入力すればいい。
    - ただし、画面が分割される。ヘルプだけ読みたいのならば、`:help | only` とすると、ウィンドウ全面を使ってヘルプを読める。参考にしながら作業したいなら、`:tab help` として新たなタブでヘルプを開き、`:tabp` や `:tabn` （あるいはノーマルモードで gt / gT）でタブを移ればいい。
- 挿入モードからノーマルモードに遷移するためには、Esc だけでなく Ctrl+[ も使える。
    - jj などを Esc に割り当てる向きもあるが、不要だろう。日本人だと jj を使う可能性もあるし……。
- 編集中のファイルを % で表せる。例えば `:!gcc helloworld.c` とする代わりに `:!gcc %` と書ける。