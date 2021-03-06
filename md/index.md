# Markdown

- [Book](book/index.md)
- [ReText](retext.md)
- [Sample](sample.md)

### 2015-11-19 Thu

- ReText は ローカルリンクで移動できない。ローカルでオフラインで、相対リンクで移動したい。
- GitHub における Markdown 文書の表示は美しい。
- GitHub による (?) Grip を用いると、ローカルなファイルを（コミットせずとも） GitHub 同様に美しく表示できるが、オンラインでないと使えない。ただしローカルリンクでの移動は（GitHub 同様、）できる。
- Geany において geany-plugin-markdown を用いるという方法がある。しかしローカルリンクでの移動はできないようであった。
- Firefox において Markdown Viewer by Thiht というものがあるが、ローカルリンクでの移動はできないようであった。
- markdown コマンドを使って markdown example.md > example.html などとすると、HTML に変換できる。

#### Markdown を用いるメリットとは？

- Markdown を用いるメリット・デメリットとは何だろうか？　私にとっての Markdown の利用価値とは？
- 最も依存性の低い自然言語の表現方法は、plain text である。特に現状、UTF-8 によるそれである。
- インターネットの発達により、HTML が極めて汎用性のある（依存性の小さい）文書の形式になった。実務においてはワード文書や PDF ファイルの存在感に陰りは見えないが、機能的制約の少なさにおいて、HTML には将来性がある。また、HTML 文書は、人間が直接扱いうるほど単純な plain text として利用しやすいため、依存性が小さい。
- よって、とりあえず指向性のない汎用な文を書こうと思ったならば、全て HTML とすることが一つの理想である。
- しかし、HTML タグの入力は面倒である。特に、多数の他者にそれを強いることは困難である。また、大抵の文書でよく利用されるタグには大きな偏りがある。そのため、頻繁に使うタグについては簡略な記述方法を用意しておきたいと考えられる。
- そのための一つの方法として、MediaWiki の wiki markup が（大きな存在感を持って）存在した。
- しかし、MediaWiki の markup 言語に類似しつつ、Markdown 言語が人気を増加させてきた。
- その理由として、MediaWiki の歴史的な文法に比べ、Markdown の文法は、（消費者よりも）生産者の利便性を重視していることがある。また、そもそもの目的の違いもあり、Markdown の規則の方が量が小さい。しかし、Markdown の方でしかできないこともある。
- Markdown 形式で書かれた文書は、plain text として直接見ても、ほとんど違和感がない。
    - 大きな見出しを表すための「#」が少ないことは一つの違和感だが、h1 などのタグとの関係がわかりやすいという利点が勝る。
- ソースを見ても人間にわかりやすいし、読むだけの時には出力を見れば、よりわかりやすい。
- また、Markdown については、GitHub の存在感が大きい。そもそも GitHub の存在感そのものが大きい。将来性のない機能には依存せず、将来性のある機能に依存することが重要であるが、GitHub があまりに大きいこともあって、Markdown の将来性への不安は減少する。
- ただ、GitHub を用いる際そのものにおいて Markdown が有用であることは、事実である。GitHub における wiki の標準の記述方法は Markdown である。
    - ただし私は別に GitHub の wiki を用いる予定はない。
    - GitHub を使う限りにおいては Markdown を使いたくなる気がするが、そうでなくなった場合に Markdown を使いつづけることを合理的と感じるかどうかは、かなりあやしい。Markdown 回りの環境の充実が足りないことが大きい。
- Markdown でもし多くの文章を作成したあとで Markdown が完全に廃れた場合を考えよう。Markdown による文書は、plain text として直接見ることにも基本的に全く耐えられる。また、多くの Markdown 文書を一括して対応する HTML 文書に変換することは、おそらく永久にたやすい。

<!-- -->

- Markdown を使うことには、デメリットも考えられるだろう。
- 得たい出力は HTML であるのに、さらに一つのレイヤーが加わり、そのレイヤー（Markdown という将来性不明の 1 方言）に対する依存性が発生することは、デメリットである。
- 例えば、HTML 文書はウェブブラウザで開けるが、Markdown による文書は、（少なくとも今のところ、）開けない。
- Markdown 言語の仕様はかなり安定しているが、GitHub におけるものをはじめ、微妙な方言が林立している。
- しかし、生産性を増加させるためには、文書作成の手間を少しでも多く減少して最適化を図ることが重要である。HTML のタグは、入力（や読む際の）手間が最小になるようにとてもよく整理されているが、Markdown に比べると、汎用性のために部分最適が犠牲になっていると言える。

<!-- -->

- plain text に対する Markdown のメリットとは何だろうか？
- リンクにより構造化できる。
    - ただし、私の環境ではろくに動作していない。
- 見出し要素によって安易に文書内の構造が表せる。これにより、自動的な目次の表示などの支援を得うるだろう。
    - ただし、私の環境では自動的に目次が利用できるような機能はない。
