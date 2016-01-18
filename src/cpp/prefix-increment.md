# Prefix Increment Operator

### 2016-01-18 Mon

- インクリメント演算子 (++) やデクリメント演算子 (--) を前置で (++i/--i)、あるいは後置で (i++/i--) 使うという議論がある。
- 前置と後置の違いを雑に言えば、a[i++] は a[i] を返して i を増加させるのに対して、a[++i] は i を増加させてから a[i]（かつての a[i + 1]）を返すというものである。
- 例えば、次の 2 種類の書き方があって、どちらを使う人もいる。
- for (int i = 0; i < length; ++i) ...
- for (int i = 0; i < length; i++) ...
- C 言語と異なり、C++ 言語では、演算子のオーバーロードが可能であって、i++ のコストが高い場合があるため、言わば C++ 特有の理由で前置が好まれるらしい。++i ならば、新たなメモリにオブジェクトをコピーすることなく、既存のデータを上書きできるからである。
- しかし、for 文で上のように int をインクリメントする場合には、コンパイラが最適化するので、出力される機械語は同一である。
- しかし、コンパイラの最適化に依存するのは気持ちが悪い。
- C 言語であっても、極めて素朴に、言語仕様に沿って C コンパイラを実装した場合、しばしば i++ よりも ++i のほうが効率的であるということはありそうである。
- C++ 言語以外を考えた時、前置と後置のどちらが一般的だろうか？
- また例えば、++exampleVariable; よりも exampleVariable++; の方が視認性が良いというのは言える気がする。文字の濃さがインデントに対して揃う。また実際、例えば Haskell 言語には標準で ++ という演算子があるので、前行の式が継続しているという疑いを生じうる。

#### -

- 「闇夜のC++」というブログに関連する記事がある。
- http://cpp.aquariuscode.com/preincriment-vs-postincriment
- 2004-10-25 - Herb Alexandrescu - C++ Coding Standards
- 28. Prefer the canonical form of ++ and --. Prefer calling the prefix forms
- Prefer to call the prefix versions if you don't need the original value.
- ...
- In calling code, prefer using the prefix form unless you actually need the original value returned by the postfix version. The prefix form is semantically equivalent, just as much typing, and often slightly more efficient by creating one less object. This is not premature optimization; it is avoiding premature pessimization.
- なおここで premature pessimization とは著者独特の言い回しで、なすべき最適化を軽視するという行為を指す。つまり premature optimization （過度の最適化）の逆の意味の言葉である。
- またここでの議論は、i++ の実装は ++i を使って行うべきである、という内容とセットになっている。
- 2014-09-29 - Jason Gregory - Game Engine Architecture, Second Edition
- 5.3.2.1 Preincrement versus Postincrement
- Notice in the above example that we are using C++'s postincrement operator, p++, rather than the preincrement operator, ++p. This is a subtle but sometimes important optimization. The preincrement operator increments the contents of the variable before its (now modified) value is used in the expression. The postincrement operator increments the contents of the variable after it has been used. This means that writing ++p introduces a data dependency into your code---the CPU must wait for the increment operation to be completed before its value can be used in the expression. On a deeply pipelined CPU, this introduces a stall. On the other hand, with p++ there is no data dependency. The value of the variable can be used immediately, and the increment operation can happen later or in parallel with its use. Either way, no stall is introduced into the pipeline.
- Of course, within the "update" expression of a for loop (for (init\_expr; test\_expr; update\_expr) { ... }), there should be no difference between pre- and postincrement. This is because any good compiler will recognize that the value of the variable isn't used in update\_expr. But in cases where the value is used, postincrement is superior because it doesn't introduce a stall in the CPU's pipleline. Therefore, it's good to get in the habit of always using postincrement, unless you absolutely need the semantics of preincrement.
- ...
- コンピュータ DEC PDP-11 では *p++ と *--p は一つの命令だが *++p と *p-- の機能についてはそうではないらしい。
- http://bokko.hatenablog.com/entry/20080606/1212695409
- 歴史的には、あるいは今も、そういった違いがあるのだろうか。
- しかしそこまで考えたくない。
- 自分としては、世間の大勢を知ってそれに従いたいというくらいに思っている。
- また、自分が趣味で書くコードについて、なるべく一貫して ++i か i++ を使いたい。
- 前置の効果を理解した上で後置を使うという考え方もできる。
- 大手コンパイラに与することを避けるために前置を使うという考え方もできる。
- i++ の動作は、そもそもどちらかと言うと特殊である。
- for 文など、 i++ が使われる場合の多くは単に、i = i + 1 と書くより短くて読み書きしやすいということである。
- プリミティブ型？と参照型？を分けて考えることができる。
- インクリメント演算子をオーバーロードした場合、どこまでもコンパイラが最適化してくれるということは期待すべきでないだろう。
- 実際、ブログの記事でも、同じソースファイルの中でオーバーロードしている場合には最適化できたが、異なるファイルであった場合に最適化できなかった場合があったと、検証されていた。
- C++ では、STL のコンテナのイテレータを操作することが多い。そこで不要なコストを生じさせないためには、C++ では前置しておいたほうが無難である、という考え方は妥当に思える。
- しかし、そのための一貫性のために、int 型変数 i について --i とする必要があるだろうか？　あるいは、int なら i++、イテレータなら ++itr などとすべきだろうか？
- 今一つ結論が出ない。
- ...ネットを眺めてみたら、（特にイテレータについての議論において？、）前置が一般的であるようである。
- 一般的であるなら、（特に C++ では）++i を使うようにしよう。
- しかし上記の pipeline stall の議論もあるから、盲目的に前置の方が効率的だと考えるのではなく、前置あるいは後置を使う理由を知っておくべきだろう。pipeline stall の議論は今の私には必要なく難しすぎるから、とりあえず軽視しよう。
- 結論 = C++ では前置インクリメント／デクリメントは一般的なので、躊躇せず使ってよい。また使うべきである。
