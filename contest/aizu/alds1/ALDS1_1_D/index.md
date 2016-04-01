# ALDS1_1_D: Maximum Profit

### 2015-12-24 Thu

- 簡単な問題らしいのだが、いきなりわからない。
- せっかくだから、なるべく答えを見ずに、考える練習をしてみたい。
- n = 6 のとき、t = 0 から 5 で、価格 R\_0 から R\_5 までが存在する。
- 全ての t で買い、買ったそれぞれを全ての可能な t で売ることが考えられる。
- ある時刻 t\_a に買った通貨を売却できる時刻は、t\_a + 1 から t\_{n - 1} までである。
- n は 2 以上である。t\_{n - 1} に買った通貨を売却できる時刻は存在しない。
- ある時刻 t\_a に買った通貨が最も高く売却できるのは、価格 max(R\_a + 1 から R\_{n - 1}) でである。
- 時刻 t に買った通貨で得られる最大の利益を maxProfit (t) と表せる。すると、複数の時刻 T を考えた時の最大の利益 maxProfit (T) は、T のそれぞれの t について maxProfit (t) の最大値である。
- 計算量を無視すると、この方法で答えを得られるように思われる。
- ある時刻 t\_a に通貨を買ったと考え、次の時刻 t\_a + 1 には通貨の価格が下がった場合、通貨を買い直したと考え、もはや元の時刻 t\_a に通貨を購入した場合については考えなくてよい。
- ある時刻 t\_a に通貨を売ったと考え、次の時刻 t\_a + 1 には通貨の価格が上がった場合、通貨を売り直したと考え、もはや元の時刻 t\_a に通貨を売却した場合については考えなくてよい。
- 以前よりも安く購入できた場合、その時刻は最大値の候補になる。以前の候補は枯れる。
- 枯れた候補は、時刻と利益の組である。
- 生きた候補は、常に 1 つだけ存在し、その時刻は、過去における通貨の価格の最小値である。
- 枯れた候補が複数生じた場合、利益が最大のもの以外は捨てられる。なぜなら、利益が最大の枯れた候補か、現在の生きた候補に負けるからである。
- 時間を後ろから見るとどうか？
- 売却を先に考えてみる。
- ある時刻 t\_a に売却する通貨を購入できる時刻は、0 から a - 1 までである。
- ある時刻 t\_a に売却する通貨が最大の利益をもたらすのは、価格 min(R\_0 から R\_{a - 1}) との差においてである。
- ...
- 時間を後ろから見るのはやめる。
- 入力が終わった時、1 つの生きた候補と、0 または 1 個の枯れた候補がある。生きた候補は枯れて、時刻と利益の組になる。枯れた候補が 2 つになった場合には、片方が淘汰される。
- これでうまくいくなら（時間）計算量は、1 回の走査だから O(n) だと言えるだろう。空間計算量は O(1) だろう。
- もしこれでうまくいくとしたならば、より良い方法はあるだろうか？　より良い方法がないということは、どのように言えるのだろうか？　もしこれでうまくいくとしたならば、これでうまくいくということをどのようにもっと整理して言えるだろうか？
- とりあえず、プログラムして、自動判定に弾かれてから考えることも考えられる。
- 最初の価格でとりあえず買う。
- もし、次が最後の価格でなく、かつ、価格が下がったならば、買いなおす。最初の価格は最大利益の候補から外れる。最後の価格で購入することは、何にせよない。
- そうではなく、もし価格が等しいか増加したならば、それを最大利益として確保する。
- さらに次の価格が、さらに増加したならば、それを最大利益として確保しなおす。前の売却候補は、最大利益の売却候補から外れる。
- 新たな価格が、既存の売却候補よりも高くなく、既存の購入候補より安くもない場合、捨てる。次の価格を考える。
- 新たな価格が、既存の購入候補よりも安い場合、それを生きた候補とし、既存の購入・売却候補を、枯れた候補とする。
- 枯れた候補が複数生じた場合、利益が最大のものの 1 つ以外を捨てる。
- 例えば入力が 100, 99, 1 だった場合、価格 100 で購入して 99 で売るのが最大利益 -1 であり、もし 99 で購入すると、1 で売るしかなく、利益は -98 になってしまう。
- それを防止するためには、価格が下がったからといって、以前の購入候補を捨てられない。
- 価格が下がりつづける場合を特別視できるだろうか？　改めてもう 1 度走査してもいいだろうか？
- 価格が下がりつづける場合、もっとも緩やかなところを探すことになる。隣接する 2 点で最も差の小さいところが最大利益になる。
- 価格が下がりつづけない場合の最大利益は 0 以上である。価格が下がりつづける場合の最大利益は -1 以下である。
- 先ほどまでの考え方では、価格が下がりつづける場合について正しく考えられていなかった。どうしてそのような間違いが起こったのだろうか？
- 全ての時刻について購入し、そのそれぞれについて可能な全ての時刻で売却して、最大値を答えとする、という、総当たり的な考えは、おそらく正しい。
- 総当たりとは英語で何と言うのだろうか？　総当たり攻撃は brute-force attack （力任せ攻撃）と言うらしい。
- まず、計算量を無視して、総当たり的に考え、そこから場合分けをして、計算量を減らしていくという考え方は、おそらく多くの場合に有用だろう。
- その際、計算量が少ない考え方が、なぜ正しいと言えるのか、総当たり的な方法との関係で示せることが望ましいだろう。
- 実数から実数への任意の関数 f(x) は、狭義単調増加の区間、一定の区間、狭義単調減少の区間、に分割できる。
- 狭義単調増加の区間において、最大利益は、始点と終点の差である。
- 一定の区間において、最大利益は 0 である。
- 狭義単調減少の区間において、最大利益は、区間における最大の傾き (slope) である。
- 狭義単調増加区間の前に一定区間が接続した場合、最大利益をもたらす購入時刻は一定区間の任意の時刻であり、売却時刻は狭義単調増加区間の終点である。
- 狭義単調増加区間の前に狭義単調減少区間が接続した場合、最大利益をもたらす購入時刻は、狭義単調減少区間の終点 = 狭義単調増加区間の始点、であり、売却時刻は狭義単調増加区間の終点である。
- 狭義単調増加区間の後に一定区間が接続した場合、最大利益をもたらす売却時刻は、一定区間の任意の時刻である。
- 狭義単調増加区間の後に狭義単調減少区間が接続した場合、接続しなかった場合に比べて最大利益は変化しない。
- 狭義単調増加区間の後に狭義単調減少区間が接続し、そのさらに後に狭義単調増加区間が接続した場合について考えよう。この時、1 つ目の狭義単調増加区間の始点を最小値 min1 と呼び、2 つ目の狭義単調増加区間の始点を最小値 min2 と呼ぶことにしよう。また同様に、それぞれの終点を max1 と max2 と呼ぶことにしよう。またさらに、abs1 := max1 - min1、abs2 := max2 - min2 と、abs1 および abs2 を定義しよう。
- min1 と min2 の大小関係は、min2 < min1, min1 = min2, min1 < min2 という 3 通りの場合に分けられる。
- max1 と max2 の大小関係も、max2 < max1, max1 = max2, max1 < max2 という 3 通りである。なので合わせて考えると 9 通りある。
- abs1 と abs2 の大小関係も、abs2 < abs1, abs1 = abs2, abs1 < abs2 という 3 通りである。3 * 3 * 3 を考えると 27 通りある気がする。がそんなにはない。
- min1 < min2 である場合、最大利益である購入時刻は min1 である。
- min1 = min2 である場合、最大利益である購入時刻は、min1 であるか、または（min1 または min2）である。
- min2 < min1 である場合、abs2 < abs1 ならば、最大利益は (min1, max1) からもたらされる。abs1 = abs2 ならばどちらか任意である。abs1 < abs2 ならば、(min2, max2) からもたらされる。
- よって、min2 < min1 かつ abs1 < abs2 である場合以外は、最大利益である購入時刻は min1 である。売却時刻は max(max1, max2) である。
- min2 < min1 かつ abs1 < abs2 ならば、最大利益である購入時刻は min2 である。売却時刻は max2 である。
- ...よくわからない。この方法で答えを得られるとするなら、変数はいくついるのだろうか？
- currentMin, currentMax, lastAbs.
- 狭義単調減少でない関数は、一定区間ないし狭義単調増加区間が 1 つ以上ある。minSlope。狭義単調減少は英語で strictly decreasing と言うらしい。isStrictlyDecreasing。単に単調減少は monotonically decreasing とか nonincreasing と言うらしい。

#### Accepted

- とりあえず総当たり的な方法で実装してみた。計算量が大きいために Accepted とはならないはずのプログラムである。結果は、Time Limit Exceeded と表示され、全 40 個のテストのうち最初の 35 個は通ったようだった。36 個目のデータが大きくて、計算しきれなかったのだろう。しかし、シンプルなプログラムで、根本的な考え方に誤りはなさそうだという印象を得ることができた。
- さらに、より計算量の低いプログラムとして事前に考えたつもりであった考え方でプログラムし、提出してみた。しかし、最初のテストで弾かれてしまった。この問題ではテストが公開されているようなので、弾いたテストをダウンロードし、ターミナルで自分のプログラムにリダイレクトして、printf などで計算の過程を観察し、デバッグした。
- その後も、あるテストに通っては次のテストに弾かれ、という感じに、何度も弾かれ、修正して、苦労して結果的には Accepted を得ることができた。Accepted と表示されたからには、これで正しいのだろうな、という感じで、論理がいまいち理解できていない。
- かなり簡単な問題に思えるのに、そしてコーディングする前に大いに時間をかけて考えたつもりであったのに、それは貢献したものの、そのまま完全とは全くいかなかった。
- また、コードを修正している時、自分が何に対して何をしているのかわからなくなり、混乱していた。コードの論理に対するクリアな理解とはほど遠い。
- 最後のデータについて例外的な処理が要求されるようで面倒だったが、いわゆる番兵として異常に低い値を置くことで、うまくいったようだ。
- デバッグ中のみ出力したい printf について、ネットの情報を参考にプリプロセッサを使ってみた。
- コマンドライン引数によってデバッグモードを切り替える実装にしてみたい気がする。...してみた。
- 1 回の走査で済ませるために、常に減少する場合を同時に処理したが、私の実力に対しては欲張ったかもしれない。分割できる問題は少ないのだから、せめて分割できるものは分割すべきかもしれない。大きな計算コストと小さな計算コストはよく区別すべきだろう。
- 最も初歩的とされる問題で、思った以上に苦労してしまったので、正しい答えや他者の答えを見る前に、もう少し考えたい。
- ...
- 正しい答えはずっとシンプル、というのはありそうである。
- ローカルでは、(signed) int は 32 ビット、long と long long は 64 ビットであるようである。サーバでの状態を知る方法は知らないが、同じようなものだろう。
- この問題では、データサイズは 2 から 200,000 であり、それぞれの値は 1 から 1,000,000,000 である。
- int の最大値は、2,147,483,647 である。なので問題の設定の 1,000,000,000 には十分。1 つ 4 バイトである int を 200,000 個確保すると、800,000 バイトになる。問題の Memory Limit は 65536 KB とのことなので、800 KB 使うことは問題なさそうである。