# 計算

### 2016-01-11 Mon

#### 遅延評価とは？

- Haskell というプログラム言語における、interact という関数における、遅延評価戦略という仕組みが興味深い。少し、書きながら考えてみたい。

#### 計算とは？

- 計算とは、何だろうか？
- 人間には、生まれながらに欲求があり、従って、喜びと苦しみがある。つまり、利益と損失がある。
- 人間は、世界から受動的に作用されるのみならず、世界に対して能動的に作用することができる。そのため、自らがどのような行動を選択したかによって、結果的な苦楽に差が生じる場合がある。
- そのため、リターンについて合理的な投資を行いたいという需要がある。リターンがより大きい投資を選びたいという欲求がある。
- 世界の因果関係を予測したいという需要がある。
- そして、世界の因果関係をより正しく予測した者達が、生存する。
- 世界そのものは、無限大の情報量を持つように見え、無限大に複雑に見える。それはそのままでは、人間の脳などの有限な計算力によっては計算できない。
- しかし、情報量を減らし、すなわち抽象化を行うと、得られた抽象については、必要な計算量が減少する場合がある。
- そのようにして行われた計算は、計算の過程で抽象化を経たため、完全に正確に将来を予測することはできず、必ず誤差を含む。
- しかししばしば、ほとんど正しい予測が得られる。そして、個体それぞれの生存性の差にしばしば劇的な差をもたらす。
- そのように、計算の目的とは、リターンの増加である。またそのための、将来予測である。

#### 過去によって未来が定まる

- 現実世界において、多くのことが、ほとんど決定的な変化を見せる。ある事前の状況を見て、ある事後の状況をほとんど確実に言い当てることができる場合がある。例えば、空中を落下しつつある鉄球は、次の瞬間、さらに落下しているであろう、といった推測が的中する場合は多い。
- 現象が確率的であって、将来が言い当てられない場合があるように見えるが、それは、抽象化された不完全な情報を用いて計算したためであって、もし実際には存在するより具体的な、より大きい情報量を用いたならば、より正確に、あるいは完全に正しく予見できたであろうという仮定は、常に可能である。
- そのため、現実世界そのものは完全に決定的な変化をする、という仮定を前提として、残りの議論をしよう。
- ある日の 1 時の世界を wt1 で表し、2 時の世界を wt2 で表すとする。1 時間前の世界を取ってそこから 1 時間後の世界を返す関数 f (w) があるとすると、f (wt1) = wt2 である。あるいは、t 時間後の世界を返す関数 f (w, t) があるとすると、f (wt1, 1) = wt2 である。この唯一の関数があれば、世界の初期状態 wt0 を与えられることによって、以後の任意の時刻の世界が得られる。
- 自らの選択によって、現在を wt11 か wt12 にできるとしよう。1 時間後の世界として、wt21 よりも wt22 を好む場合、f (wt11) と f (wt12) のどちらが wt22 をもたらしてくれるのかが気になる。しかし、それぞれの選択の結果は決まっているから、無限大に複雑な世界についてもしそのまま計算することができれば、必ず好ましい戦略を選択できる。
- Haskell や Lisp やラムダ計算では、「評価」という言葉を使うらしい。
- 現在として wt11 を選べば 1 時間後には wt22 が得られるのであれば、式 f (wt11) を評価していけば、値 wt22 になる。そうではなく、（あるいはそうであってかつ、）wt12 を選んで wt22 が得られるなら、f (wt12) を評価して wt22 を得られる。ゆえに、評価してみて wt22 が得られた戦略を選べばよい。
- ここで、評価するとは、その間に世界の万物に相互に働く因果関係を実現してみるということであると考えられる。
- その評価において計算を実施するのは、世界そのものであるか、世界の完全なシミュレータである。
- よって、世界は、無限に複雑に見える彼について、無限大の計算力を持った計算機であると考えられる。

#### 因果関係という式木

- しかし、有限な計算力の脳を持ち、未だ有限な計算力しか持たないコンピュータしか手にできない私達においては、有限な計算力を用いて、なるべく有意義な計算結果を得たい。
- そのためには、計算に用いる値や演算を抽象化して簡略にし、結果に大きく作用する部分を重視し、結果に大きな誤差を生じない部分を軽視あるいは無視し、計算量を下げることで、計算結果の精度を高めていくことが好ましい。
- あるいは、そのような方法で計算可能になる問題について高々計算し、貧しいながらも、得られる利益を確保していきたい。
- そのため、本来、現実の因果関係を完全に表現していた値は、一般に遥かに抽象化された、極めて単純化された因果関係として表されることになる。
- その抽象化された因果関係が、人間が一般に書く式である。
- もし人間に無限大の計算力があれば、数学はいらない。数学は、人間やコンピュータという計算機のために問題の計算量を低下させるための技術である。
- 例えば、Haskell プログラムは、関数らの構造を定めたものである。関数には一般に細かく名前すなわち識別子が与えられるが、識別子を全て展開して概ね同じものを書くこともできるから、全体としては、1 つの式木を表した、定義した、抽象化したものだと考えられる。
- ある Haskell プログラムは、その式木によって表される、1 つの関数である。必ず一定の出力をもたらすのでないならば、その関数は引数、つまり入力を取る。プログラムは、入力値の様々な場合について、それぞれのための出力値を定めたものである。プログラムには、場合分けと、分けられたそれぞれの場合についての値が書かれている。
- 遅延評価戦略においては、木は根から評価され計算されていく。
- 遅延評価戦略は、計算量を低下させるための方便であり、もし計算力が無限大であるならば、先行評価戦略を取っても同じである。プログラム全体を表す式木の全ての葉から全体を計算していっても、出力される値は同じである。
- このような具体的な議論は、正確に言えばおそらく的外れなのであろうが、主旨としては、そう考えてみる。
- 遅延評価戦略とは、本質的に、そのようなものであると思われる。
- すなわち、遅延評価戦略とは、計算量を減少させるための技術であり、つまり抽象化である。
- 遅延評価戦略においては、式木は、必要になった部分が必要な分だけ評価され計算される。
- それは人間が、世界について、重要だと思った部分らのみによって因果関係を書こうとすることと似ている。
- 抽象化されたものが式木であるならば、そのより具体的であったものもまた式木であると言える。
- よって、現実世界はまた、1 つの式木である。先の言葉で言えば、wt1 とその世界の 1 時間後の状態 wt2 は、wt1 を根とし wt2 を唯一の葉とする式木によって結ばれている。その間の過程は、因果関係による時間的な変化を定める関数 f によって表される。遅延評価戦略によれば、wt1 を評価していけば、wt2 が得られる。
- 世界という計算機は、常に現在世界を取って、関数 f に与え、それを評価して、無限大に見える計算力によって、次の瞬間の世界を表している。あるいは、世界の初期状態を取って、世界の終了までのそれぞれの時刻の世界を、例えば 4 次元的に表わしている。

#### 物理的時間と数学的計算

- 例えば人間の脳は、特に人工のコンピュータに比べて、連想が得意であると言われる。
- 連想機能は、必ずしも事実的な因果関係がそこになくとも、因果関係を認知する。
- それによって人間は、本来、無限大に複雑に見える現実を、抽象へ抽象化しているのだと考えられる。
- 抽象化は、それ自体、計算だろう。
- 例えば、ある人々の平均体重を得ることで、情報量を減少しつつ、しかし有意義な計算をすることができる。計算力資源が有限であるために、情報量が減少することによって、しばしば計算結果の精度は大きく増加する。
- もし、無限大の計算力があれば、統計的な抽象化はいらない。
- 例えば、犬のようなものを纏めて犬と呼び、犬と連想される範囲を共有したならば、個人的な思考にも、集団的な議論と思考にも便利である。
- 自然言語は、極めて抽象化された情報の形であるが、自然言語を利用しながら計算している人々の脳で行われている計算は、一般に、自然言語よりはずっと具体的である。
- 例えば、すでに述べた平均体重の計算は、過去の情報から将来の状態を推計しているわけではない。
- しかし、人間としては、計算する理由である最終的なゴールは、選択する投資に対するリターンの増加であり、そのための精度ある将来予測である。
- よって、計算とは、人間の脳や人間が利用するコンピュータの計算力が有限であるがゆえに初めて、その過程において抽象化を必要とするものである。
- よって、平均体重を求めるという統計的な抽象化についても、その間接的な目的は、世界についての時間的な将来予測であると考えることができる。
- よって、全ての計算は、将来予測のためである。
- 現実世界そのものも、精度が完全な将来予測をしていると考えることができる。私達の目的は、世界という計算機が行う将来予測になるべく近い将来予測をすることである。
- 一見、数学は、物理学を越えた普遍性を持っているかに見える。しかし実際には、より具体的でより世界そのものに近い物理学のほうが、普遍性を持っていると考えられる。抽象的な抽象は、とりあえず、人間固有の、計算の方便だと考えたほうが、安全だと思われる。よって、人間から見て一般に、一方向的に移動している時刻について、計算がそれよりも下位の普遍性を持っているものとして考えることは、許されると考えられる。

#### 運命の中における自由

- 世界を決定的に推移するものと見るならば、その部分における人間それぞれには、主体的な自由性は存在しないことになる。
- そうであってかつ、人間それぞれにとっては、主観的な自由性が存在しており、主体的な計算が存在している。
- では、河原の小石や空の月は、思考しているだろうか？
- 思考を、世界にある部分を見て、そこへの入力と出力の間に内部で生じた過程であると見るならば、万物は思考していると言えるだろう。しかし、人間の主観的な価値観と程度の感覚から、一定以上に複雑でなければ思考とは呼ばないと考えるならば、思考していないだろう。また、普通な対話の相手にならないならば違うと考えるならば、コンピュータは計算機ではあっても思考はしていないと言えるだろう。しかし、そういった歴史的で世俗的なナイーブな感性を除いて言うならば、単に、万物が常に計算しているものと考えるべきだろう。
- その類推は、実際にコンピュータのシミュレータの上において種々の人工知能が動作している現在においては、やりやすい。あるアクターは、角を曲がって初めてそこに食料が置かれていることに気がつくかもしれないが、シミュレータ環境そのものは、そこに食料があることを以前から知っており、その時必ず彼がそれに気づくことも決定論的にわかっていた。
- 現実世界の神は私達の上に君臨していて逆らえないが、私達は、より下の世界を見れば、例えばシミュレータにおいて、私達自身、神になることができる、とでも例えて言える。
- であれば、シミュレータに限らず、あらゆるプログラムの記述、あるいは計算の実施を行うことは、下位に世界を創造しているのだと言えるかもしれない。
- しかし、人間にとってそれは所詮、現実に生まれて与えられた欲求を満たすための行動であるにすぎない。

#### 世俗的応用

- 適切に思考するとは何だろうか？
- あるプログラムを適切に記述するとは何だろうか？
- ソフトウェアを作成するにあたっては、要求定義というものがまず重視される。しかし、例えば実現不可能な要求を定義しても仕方がない。
- いつだって、ある投資をすればあるリターンがある程度期待できる、という、一見厳密な根拠のない認知がある。
- そうして、これだけ資源を投入すれば、これだけの機能の製品が作成でき、これだけの利益が見込めるだろう、といった認識が、集団においていくらか共有されていく。
- そうして、これだけの資源でこれだけの機能を作成せよ、という責任が生じる。
- 実際には資源を大きく消費し、機能は小さく生じたならば、好ましくない。資源を小さく消費し、機能を大きく生じるほど、普通、好ましい。
- トップダウンに戦略は指揮され、ボトムアップに実現性は報告され、平衡の中で時刻は進んでいく。
- 中央からの指示によって末端は鋭敏に動作することが望ましく、末端で感知した状況に応じて中央の判断は劇的に変化することが望ましい。決心しなければ勝利に遅れ、逃げることを知らなければ死ぬ。
- 一見、入力と出力の仕様を満たすプログラムは、様々に実装できる。
- バグが少なく、保守性が良いプログラムを書くためには、最も抽象的なレイヤーにおいて、論理構造が数学的で美しいことが重要である。それは結局、どのような人材をどれだけ側に置いておけるか、ということと影響しあうかもしれない。ある程度は俗で、多くの者が理解を共有できることが好ましい。
- 本質的に正しく、論理的で堅牢なプログラムを書くためには、プログラミング言語や開発環境による支援が重要である。ゆえに、それぞれの現場とそれぞれの時代によって、最適な答えは異なるのだろう。
- 適切に思考するとは、良い推測を行い、結果的に良いリターンを得るような思考のことだろう。そのためにはやはり、本質的に正しく考えるべきだろう。特に、人間やその集団を、自分自身も含めて客観的に見るために、その思考を、コンピュータの議論を用いて、計算として一般的に理解しておくことは好ましいだろう。
- 人間らがプログラムを書いて、コンピュータがそれを動かして、何かを得るということは、人間が得意な部分を人間が計算し、コンピュータが得意な部分をコンピュータが計算する共同作業である。また、人間同士の協働も、計算機らによる協調的な計算だと言える。
- そこにおいて、本来、無限大に複雑な現実について、誰が何をどう抽象化し、何をどう計算しているのか、理解することは便利だろう。また、自分自身がその時々に行っていることが、いったい何を行っているのか、客観的に見えるようになることは便利だろう。
- コンピュータには、複雑な現実は直接扱いにくい。人間のほうがましである。そのため、人間が、現実を抽象化して、コンピュータに処理可能な論理構造にしてやる。コンピュータは、高級な擬似コードならぬコードを読んで、現代のコンピュータ特有のハードウェアに合わせて具体化し、結果を計算する。
- 抽象化の意義については、数学やプログラミングのみならず、人間の脳が関与する問題一般について、有用である。同様に、遅延評価戦略や式木や評価という考え方についても、世俗の中で有用性があると思われる。
- 私の興味は、そういった応用性にある。私は、いわゆるコンピュータやプログラミングや数学について、それ自体への熱心な興味はなく、手段として興味を持っている。私の興味はどちらかと言えば、いわゆる数学で最も記述しにくいような例えば精神的、社会的な議論について、数学やコンピュータサイエンスの一部を利用することにある。

#### プログラミングコンテスト

- プログラミングコンテストというものがある。プログラミングコンテストを実現するための機能はサービスとして無料で公開されており、優れた人々の競技のためのみならず、広く初学者の練習のために用いられている。
- プログラミングコンテストでは、設問があり、ユーザがプログラムを送信すると、テストデータが入力されて、出力の正しさからプログラムの正しさが判断される。
- もし、コンピュータがすでに十分に賢かったならば、プログラムに設問を入力したら正しいプログラムが完成し、人間が担当すべき部分はない。実際には、コンピュータはまだそこまで賢くないので、人間に担当すべきところがある。あるいは、コンピュータがすでに賢かったとしても、あえて人間にそれを練習させることは意義があるかもしれない。
- そこにおいて、人間が担当している作業、計算というのは、何なのだろうか？　いかなる入力についていかなる出力を出すべきか、つまり要求される仕様は、問題文においてすでに記述されている。ユーザがなすべきは、その実装を、特定のプログラミング言語によって表現することである。
- 実装の表現には、擬似コードというものが使われることがある。擬似コードは、特定のプログラミング言語に依存していないと言えるかもしれない。しかし、命令型の擬似コードは、関数型のプログラミング言語、例えば Haskell にはそのまま記述しにくいことが多いし、時に簡単な数学的な関数定義は、そのまま Haskell に記述できる。よって、プログラミング言語に対して完全に普遍的な擬似コードがあると考えるべきではないだろう。最も普遍的な擬似コードとしては、既存のものを利用して、命令型なら Java、関数型なら Haskell、より広汎な話題については自然言語、としておくぐらいが良いかもしれない。
- 入力が少数の有限個で、出力もまた少数の有限個である場合、普通、仕様を満たすプログラムを書くことはたやすいだろう。背景的議論がいかに高度であれ、実装においては、簡単な場合分けをして、既知の定数を出力すればいいからである。
- しかし、例えば入力された整数 1 から 100 を倍にして出力することを求められた場合、例えば C 言語の if 文で 100 個の分岐を作ることもできるが、そのプログラムを書くのは手が疲れるし、時間がかかるし、見通しが悪くなるので、積を計算する関数ないし演算子を使いたくなるだろう。そのように、プログラムの本質が関数であって、場合分けであるとしても、実際のプログラムは、単純ないわゆる場合分けという雰囲気からは遠ざかる。
- 計算の最も本来的な目的は、将来予測である。初期状態を入力として与えられた時、そこそこ精度の良い出力をもたらすことが期待される。
- プログラムは本質的に、関数である。初期状態をとって適当に計算して出力する関数をいくつか考えてみた時、比較的に精度の良い出力をもたらす関数が、良い関数であり、そうでない関数が、悪い関数である。良い関数は、しばしば天才によってのみ見出される。良い関数は、しばしば企業秘密あるいは軍事機密であり、利益を生む根本的な資産である。
- よって、関数は普通、仮説であっていい。その因果関係の見通しは、妄想や言いがかりであってよい。結果的に実用性があり、利益を生めばいい。現実の多くのことは、所詮、確率的にしか推測できないからである。
- 一方でまた、論理的な演繹によって、完全な議論をしようというのが、いわゆる数学の基本的なアプローチだろう。例えば、プログラミングコンテストにおける問題は普通、設問によって完全な論理がすでに記述されており、つまり要求定義が理想的であって、迷いなくプログラミングに向かうことができる。
- 実際の問題においては、そのような完全な要求定義が難しいことが多く、なるべくよい要求定義を実現するまでが難しい。経験的な判断が多くなされるが、統計的な判断が有効であることが多いとはいえ、統計的な数理的に記述できない、それぞれの人材の経験と勘によるところが大きい。その問題は、人間の脳を既存のコンピュータが代替できない以上、解決されるものではないし、解決を望む必要もない。人間の脳に依存しないようにすることも重要であるが、人間の脳を活かすことも重要である。
- ゆえに、プログラミングとは、必ずしも、完全な論理をプログラミング言語で書くことではない。
- プログラミングとは、プログラムを書くことである。プログラムを書くとは、関数を実装することである。関数を実装するとは、入力の場合に応じた出力の対応を記述することである。その記述の表現の方法が、プログラミング言語である。
- 計算とは、関数に引数を適用して評価することである。関数を評価することである。プログラムとは関数であるから、プログラムを実行するとは、関数を評価することである。人間の脳は、一種の計算機である。人間の脳には、関数を保持する機能と、その関数を評価する機能とがあるのだと考えられる。ただし、人間の脳は常に変化している。
- 関数は、静的に記述できる。同じ入力に対するある関数の出力は常に一定だから、入力が同じなら、関数を評価する必要は必ずしもない。キャッシュという関数にキャッシュしておけばいいからである。別の入力が生じた場合には、関数に出力を問い合わせなければならない。
- 計算の根本的な目的は将来予測であり、脳という関数を評価する理由もそれである。脳に記述されているのは、抽象化された現実世界であり、それによって精度ある将来予測が生じる。脳に抽象化された世界を書いた、すなわちプログラミングしたのは、自然選択である。人間は、自らの種の知的な限界を相対化して考えることができる。
- 人間は常に、脳にエネルギーを供給して、新しい時刻の世界を入力として関数評価している。また、自分自身という関数を常により良く更新しようとしている。
- ある与えられた考え方や価値観に満足することは、関数を更新しない方向性の振る舞いだろう。新たな考え方や価値観を模索することは、関数を更新しようという方向性の振る舞いだろう。
- 静的な知識を蓄えるということは、脳という関数の部分に定数を内部化していくことだろう。
- 人間の脳には、個人によって多様な特性がある。
- C 言語などの命令型言語では、実行すべき順序通りに、プログラムの文のリストが記述される。一方で、ラムダ計算の考え方に基づく関数型言語の 1 つである Haskell では、プログラムの表面上の表記の通りには実行されない。しかし、ラムダ計算の考え方によって関数で書かれたプログラムであっても、その評価の順序を展開して変数を多用するなどすれば、実行順序通りのリストに変形できるだろう。
- よって、命令型プログラムとは、計算、関数評価寄りのプログラムであり、関数型プログラムとは、関数寄りのプログラムである。
- よって、プログラムが人間によるバグを恐れて高級化していく中で、関数型に近づいていくことは、自然なことであると思われる。
- Haskell でプログラムしていると、表現が実行順序通りでないことが煩わしく、C などのように実行順序通りの表現である方が好都合なのではないかと思えるが、表現が実行順序通りでないことは、関数型言語であることの本質的特徴の 1 つであり、関数的に表そうとすることの表れである。
- どちらかと言えば、歴史的なプログラムでは、仕様書の文書の中に関数で記述し、それを C やアセンブリ言語で命令的に記述していた。一方で、Haskell を用いると、仕様書に書かれた論理的制約をより多く、プログラムのソースコードそのものの中に表現することができる。それによって保守性の増加が期待できる。
- そのために、プログラミングが Haskell などによってなされることを通して、プログラミングの本質へと視点が近づいていく。関数評価が捨象されていくことで、関数そのものについて考えることがしやすくなる。

#### 繁殖する式木

- 関数は関数を創造できる。
- 実際、脳は、入力に応じて次の瞬間の脳を定めているし、人間は、そのままではコンピュータが計算できない問題をプログラムにプログラミングできる。
- プログラミングにおいては、ある問題を与えられた時に、それを解く方法を思いつく必要がある。釘が与えられたら、道具箱から金槌を取り出すようにである。そのためには、その道具を使った経験が大切である。経験があれば、必要な時に連想できるからである。
- プログラミングにおいてはまた、ある解く方法について、その正しさが説明できる必要がある。数学で言う証明そのものだろう。証明にあたっても、そのための道具を使った経験が大切だろう。
- 私達の脳は、日々、思考し、判断している。その脳は、ある瞬間、突然狂気に転落する可能性を持っているだろう。そして、狂気に転落したことは、それ自体によって自覚されないだろう。
- ある推論が、実際には失敗であったことは、失敗を経験することによって理解される。推論が狂気に堕落しないためには、現実との矛盾のなさを、総合的に検証しつづける必要がある。
- プログラミングコンテストにおいては、特に簡単な問題についてだけかもしれないが、設問を読んで、理解されればすぐにプログラムされることが多いだろう。しかし、プログラムには普通、証明を記述する必要はなく、記述されない。本質的には、より高級な、計算的ではなく数学的な、証明の文書が記述されるべきだろう。証明は重要である。
- しかし、正しいプログラムが書ける場合であっても、それを導いた考えを言葉にすることは難しいし、しばしばプログラムを書く以上に手間である。また、プログラムが正しいからといって、それを考え出す経緯の思考を全て言葉にできたとして、それが直ちに証明であると言えるのだろうか？
- 私としては、とりあえずは、このように、文書を書きながら考えることを大切にしていきたいと思う。
- そこにおいて大切なのは、未熟で的外れな仮説を平然と記述することであると思う。
- 間違いが間違いであることを言うことが、正しいことを正しいことだと言うことであるからである。外部から低く評価されることを恐れて多様な検証ができなくなることは、危険なことである。
- プログラミングは、人間という関数が関数を出力することだが、その過程においては、数学に類似した証明に類似した計算が行われている。
- 関数は、証明を創造できる。
- 〜ならば〜である（ということが常に真である）ことを証明する。A ならば B であるとは、A でないかさもなければ B であることである。
- ある証明によって証明ができているのかどうかを考えると、数学的な難しい議論になってしまいそうだから、そこを重視しないことにしよう。
- それぞれの領域で必要な議論を経験することを通して、議論の方法を考えていこう。いわゆる数学の専門家には（なりたくてもなれないが）ならないようにしよう。
- しかし、計算というシンプルなイメージを、議論という汎用な話題に広げようとすることは、常にしていきたい。
- プログラムは関数である、脳は関数である、世界は関数である、などと言うことに意味があるだろうか？　プログラムは式木である、脳は式木である、世界は式木である、などと言うことに意味があるだろうか？　人間が用いる関数は、世界という関数を抽象化したものである、といった議論ができるようになるような気はする。
- 入力に対して出力をもたらすものを、総じて式木と呼ぶことは許されるだろうか？
- 式木を書いておいて、その式木を評価すると、出力の値が得られる。
- 帰納するというのは一般に、抽象化である。現実そのものは、本来、帰納を許さない。正確なことが言えるのは、現実そのものによってのみだからである。演繹というのは、言い換えることであって、実際には何も言っていない。しかし、帰納も演繹も有用であり、どちらも難しい。
- いわゆる数学的証明は、演繹的証明である。
- 良いプログラムとは、良い関数、良い式木のことである。
- 証明とは、式木を（正当に）変形することである。
- 式木は式木を創造できる。
- 要求定義とは、それもすでに式木である。実装するとは、式木を変形することである。しかし実装では一般に、証明と違って、正当性の表現は失われる。
