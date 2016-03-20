# Programming

### 2016-03-08 Tue

#### コメントのスタイル

- コメントについて。
- プログラムのソースコードにおいて、機械が解釈せず、人間による人間のための脚注が付されることがあるが、それをコメントと呼ぶ。
- プログラミングにおいて、最も古典的で枯れたスタイルは、1 行の内容を 80 文字以内に収め、また、表示行の折り返しがないテキストエディタを使うものだろう。
- その場合、ブロックコメントについて、各行の冒頭に修飾を施すことが多い。そのような場合、人力で、80 文字改行で編集することは、編集のたびに改行位置を修正する必要が生じ、生産的でありえないだろう。自動支援によって問題がない場合もある。また、日本語を使うと改行について半角スペースと見なされる環境があり、煩わしい。
- Java 言語におけるツール Javadoc のように、コメントを特定の形式で書くことで、文書を自動的に生成してくれる場合がある。大きなプログラムを複数の人々で扱う場合などに、とても有効だろうと思う。しかしその対象は普通、関数ごとなどである。実際には、より細かくコメントを書きたい場合がある。
- 統一モデリング言語 (Unified Modeling Language, UML) というものがある。それによって表現されるように、プログラムというものは、抽象的なモデルと具体的なコードとが上下に連続した構造を持っている。リッチな、あるいは理論上望ましい統合開発環境においては、相互に自動的に生成され、操作すれば相互に自動的に同期されるだろう。しかし実際には、技術の進歩はそこまで理想的に進んではおらず、様々な面倒や弊害が生じるので、依存を避けるためにも、C 言語を単にテキストエディタで書いてコマンドラインでコンパイル、といったシーンは多い。
- プログラムを変更したがコメントや文書の変更はされなかったために整合性が失われた、という場合は生じやすいが、問題である。プログラムと文書は、相互のリンクがないことが多く、またプログラムの変更に対してより上位の抽象である文書の正当性を自動的に確かめる AI も実現しがたいために、人間が、プログラムの変化を文書の変化へと正しく対応させようとしても、言わばドキュメンテーションのバグは頻出するだろう。それに対する一つの対策は、消極的ではあるが、なるべくコメントを書かないことである。
- コメントの書き方について、例えばプログラムのある 1 行について、その上に書くコメントと、右に書くものと、下に書くもの、3 つのスタイルが考えられる。
- 下に書くものは一見、上に書くものと区別しがたいが、下に書いた場合には次に空行を設けることをすれば問題ない。すると、上に書いた場合は複数行に対して、下に書いた場合は 1 行に対してのコメントである、といった使い分けができる。
- 私が最近いいなと思ったのは、右に書くコメントである。
- その利点は、行数が増えにくく、また、コードだけを眺めることを妨げにくいことである。
- Emacs の設定ファイルの Emacs Lisp を編集していると、それぞれの行はまるで暗号で、コメントは不可欠に思える。しかし、相互に関係があったりなかったりするいくつもの命令が羅列され、長いので、コメントするたびに行を追加すると、見通しが悪くなる。
- 右側コメントを用いると、コードが短くてコメントも短い場合には表示行が増えることもないし、テキストエディタが支援して着色表示してくれれば、コードとの区別について目が混乱させられることも少ない。
- なるべくコード自身によって語らせるべきであり、コードから自明であることを必要以上にコメントすることは有害である、ということがしばしば言われる。
- しかしそれは一般論であって、例えば初めて学ぶプログラミング言語については、一つ一つのキーワードの意味もわかりにくく、コメントをつけて確認することが勉強のために良い場合もあるだろう。そのように、自明性の程度は状況によるため、コメントの粒度も状況による。ゆえに、具体的なところについては、あまり一般論は通用しない。
- 複数の人々が共同してプログラムを開発する場合にはコーディング規約による一貫性を重視する。しかしそれをここで考える必要はないだろう。
- Linux Kernel Coding Style に、コメントについての議論ではないが次の記述がある。
- However, never break user-visible strings such as printk messages, because that breaks the ability to grep for them.
- Unix ハッカー達は、確率的な方法を効率的に使いこなすようである。例えば巨大なソースコードに対して自然言語で検索や grep を行い、自然言語の慣習のパターンから問題を探しだし解決する。grep など、Unix のコマンドでは、改行は意味を持つ。
- 改行によって、1 つのテキストファイルが言わば配列としての意味を持つ。あるいはリストである。プログラムの場合、ファイル名が関数名であると考えることができ、実装はリストであると考えることもできる。しかしファイルは再帰的な構造ではない。しかし、1 つのファイルを配列にしたことで木構造やグラフ構造が表現でき、任意の次元に広がることができるだろうから、改行によって再帰的なのだと見ることもできる。
- 例えば、プログラムを使っていてエラーメッセージが表示された時、ユーザはそのメッセージでソースコードを grep するかもしれない。そのような時、メッセージの途中が途切れていると grep できない。
- Unix ハッカー達は、自然言語で計算することの価値を知っているのだと見なせる。ゆえに GUI よりも CUI を愛するのだと考えることもできる。自然言語の価値は、それが離散的でデジタルであるところにあると考えることができる。例えば、画像に関する diff コマンドの仕様は標準化しにくいだろう。
- 歴史的には、8 文字タブが使われたようだ。Linux Kernel Coding Style では 8 タブを推奨している。4 空白によるインデントは、支援によって使いうるが、タブが 8 文字分であると前提していいなら、タブの利用は快適である。しかし、4 空白文化から見るとかなり奇怪だろう。
- 右側コメントは、空白の後に書くこともできるし、タブの後に書くこともできるだろう。しかし、縦に揃える場合もあると考えるなら、インデントに合わせてタブで合わせるのが自然であると考えられ、そうであれば、一般に常にタブを用いることが自然に思える。
- アルゴリズムについて、計算量という概念がある。プログラミングコンテストあるいはオンラインジャッジといったものにおいては、計算量が重要である。Haskell の標準ライブラリの解説には、関数ごとによく計算量が書いてあった。関数、あるいはループについて、計算量を考えてコメントすることは有意義かもしれない。しかし、計算量は呼び出し先の計算量に依存するので、下位に変化があった時にはコメントの整合性が崩れてしまうかもしれない。
- コメントは、英語によるものが、最も汎用性があり理想的だろう。
- しかし、自分も英語が分からず、同僚の英語が分からないような状況では、共通の母語として日本語などを用いるべきだろう。Unicode、UTF-8 が広く使われるようになり、日本語を扱うことはとても簡単になった。
- 例えば、日本語でコメントを書くとコンパイルエラーになる、というようなことはほとんどないようである。しかし、ウェブサービスなどにおいて、日本語が正しく使えないとか、データファイルにおいて数字の列にエンコードされてしまうということは見られる。不便は少し残っているし、続くだろう。
- 変数や関数をどう命名するかは、悩ましい。
- 私は、長い名前が好きである。自然言語との連続性を重視することが保守性を大きくすると思っている。
- しかし、長い名前は、低い実装においては、アルゴリズムの見通しを悪くすることが多い。短い名前を用いた方が明らかに合理的な場合はしばしばある。
- また、タイプする手間も無視すべきものでない。
- 変数名の命名法とコメントのスタイルには関係がある。変数名が自己説明的であるほどコメントは少なくできるかもしれないし、変数名が簡潔ならばコメントで説明を補ったほうが良いかもしれない。
- ローカル変数には短い名前、グローバル変数には長い名前が適している、といったことは一般的に言えそうである。ローカル変数などについては、短い名前を与え、初出の際に、変数名で表しうる程度の説明はコメントしておくことが便利だろう。グローバル変数など、変数のスコープが数ページに収まらないようなものについては、意味を記憶しておくのは邪魔であるから、ある程度それ自身で説明的な名前がふさわしいだろう。
- しかし、名称を捨ててしまったほうが、アルゴリズム間の本質的な共通性が現れる、という面もある。その意味で、名称やコメントの利用は、ある同じ問題に対し、ある視点からの見方を融合させてしまう面もある。
- 勉強会などで、自分の実力ではついていけない講義がなされる場合がある。そのような場合、与えられた資料について、カンニングというか、多く書き込んでおいて、実際の講義ではそれを利用することが有用である。そのような場合のコメントというのは、非常に実用性がはっきりしている。
- 問題の理解の仕方というのは、人によってひどく異ならないことが多い。そのため、あるソースコードについて、ほとんどの人に有用でほとんど無害なコメントのあり方というのはあるだろう。
- また、ノートを取りながら思考することは、ほとんどの問題について有用だろう。
- 例えば、Linux - bash - C という組み合わせは、枯れた関数群、テキストシェル、portable assembly という組み合わせであり、大いに普遍的な価値を持っていると思われる。（それより下のものと上のものは、それほど普遍的ではないと思われる。）　その上に自然言語を乗せることで、人間の任意の計算と連続性を持たせることができると考えることができる。そのような視点から見ると、例えば C 言語のソースコードに対するコメントというのは、重要な接続点であるように見える。
- ゆえに、適切なコメントをつけようとすることは、考えることの訓練として良いだろう。