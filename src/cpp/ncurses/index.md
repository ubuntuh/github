# ncurses

### 2016-01-29 Fri

* Unix 系の環境で、GUI アプリケーションではなくコンソールアプリケーションを作成する際、直列的に文字列を出力することが最も簡単だが、画面を更新していくことで、CUI 端末上で言わば GUI に似たユーザインタフェースを提供することもできる。
* そのための代表的なライブラリが ncurses である。
* ncurses は、歴史ある curses というライブラリを 1993 年から現代的にしたものであり、すでに広く使われている。
* ncurses の元になった curses は、Ken Arnold によって作成された。Ken Arnold は、広く使われた Rogue というゲームプログラムの作者であり、Rogue の実装にも curses は使われた。
* そもそも、端末を制御することは普通、特殊な文字によって行われる。よって本来、例えば C 言語の printf 関数だけを用いても、任意の端末制御を実現でき、GUI 様のプログラムの作成は可能である。しかし、そのための制御文字には端末プログラムによって方言があり、curses にはそれを覆い隠す機能がある。ゆえに、インタフェースとして curses を用いておけば、広く Unix 系 OS 上で動作することが期待できる。
* sudo apt-get install ncurses-doc とすれば、man ncurses とすることでドキュメントを読むことができる。
* sudo apt-get install ncurses-examples とすれば、/usr/lib/ncurses/examples に、いくつかのサンプルプログラムがインストールされる。
* sudo apt-get install libncursesw5-dev とすると、gcc helloworld.c -lncursesw などとして、日本語などが表示できるようになる。
* curses によって作成したプログラムは、X Window System を利用していないので、X Window System が起動していない環境でも動作する。
* 単純な CUI アプリケーションには、多くの利点がある。また、グラフィカルな表現力においては、普通に X Window System の上で動作するほうが優れている。グラフィカルなターミナルアプリケーションの有効性は、限られていると思われる。
* 私がすでに実用しているグラフィカルなターミナルアプリケーションとしては、emacs がある。top コマンドというものも見たことがあるが、使っていない。emacs をターミナルで使うのは、bash と行き来しやすいからだと言える。X Window System 上にウィンドウが増えないので、フォーカスが混乱しない。bash などのテキストシェルをベースに考えた場合、それは一つの利点である。

#### -

* bash を使っていて思うのだが、ファイル名を入力するのが面倒くさい。キーボードによるインタフェースは、長所でもあるが、短所でもある。
* nautilus などの一般的な、グラフィカルなファイルシステムブラウザでは、マウスとそのクリックでほとんどの処理が行える。（マウスなどを認識しない歴史的な）BIOS 設定などでは、カーソルキーと Enter などでほとんどの処理が行える。近年流行のスマートフォンやタブレットでは、タップのみによってほとんどの処理が行える。
* しかし、タップのみによってプログラムや文書を書いたり、bash を操作することは大変である。現代的に洗練された機械を使っているつもりでいても、与えられたものを使う無力なユーザになってしまう危険がある。
* Unix 系のコンピュータ環境には、非常な歴史がある。そして、GPL は、ユーザの自由性のためのコアコンピタンスである。
* CUI から GUI への発展は、進化ではない。CUI は永遠である。多くの人にとって GUI だけ使うことが当たり前になっても、優れた人々は CUI を使っている（と仮定してみよう）。
* C 言語などによるコンソールアプリケーションと、bash などによるそれへのパイプ、リダイレクトは、永遠である。そのレベルの標準の普遍性は、他のプラットフォームに隔絶している。データ形式としての ASCII テキストと、関数（機能）の（最小）単位としてのコンソールアプリケーションという形態は、個人ユーザのためには、ほとんど永遠に汎用である。
* コンピュータのプロフェッショナルではない者が、私的便宜のためにコンピュータを使う場合においては、少数の部品を少数個組み合わせて機能を創造するのがせいぜいである。そしてそれは、長く使えるものでなければならない。ゆえに、依存性の排除は、個人においてこそ優先される。
* 歴史的な携帯電話に比べると、現在の携帯電話は、何でもできる。一般的なパソコンと OS は異なるが、ブラウザ上でのプログラムの提供は、JavaScript で共通している。HTML5 + JavaScript が、今、極めて汎用なプラットフォームである。そのように、世界は、大きくて、無料で、本当に良いもの、に吸収されていく傾向がある。あえて沈む船に乗るのはよくない。
* しかしまた、携帯端末で何でもできる日は来ない、というのも真実だろう。既存の携帯端末でも、JavaScript プログラムを消費することは簡単でも、生産することは難しい。少なくとも私が死ぬよりもずっと長く、Qwerty キーボードが王者なのだろう。Linux + Bash + C + Qwerty というプラットフォームは、とても強い。世の中の流行はそこからどんどん離れていっているように見えるが、優れた人々はそこを根城にしている（かもしれない）。
* そのような視点から見ると、curses を用いたプログラミングも、意義はある気がする。
* ノートパソコンとスマートフォンは、とても似ているが、とても違うものである。なぜなら、ノートパソコンにはキーボードがついているが、スマートフォンにはキーボードがついていない。だから、スマートフォンをノートパソコンの代わりにすることはできない。（スマートフォンにもキーボードをつけることはできるが、ここで考えている主旨とは関係がない。）
* プロプライエタリよりもオープンソースが好ましく、オープンソースよりもコピーレフトが好ましい。なぜなら、プロプライエタリに依存することは罪のない人々の血でパンを買うことであり、オープンソースに依存することはプロプライエタリを助けることだからである。法律的な権利に関係して潜在的な戦争が行われている。
* 現在、日本で流通している一般的な携帯電話では少なくとも、電話機能はモジュール化されていないだろう。よく知らないのだが、携帯電話の OS をプロプライエタリなものからオープンソースなものに入れ替えることは難しいだろう。
* Ubuntu は、もといカノニカル社は、タブレットやスマートフォンへの Ubuntu の対応を積極的に進めているようだが、それがどの程度実用されているのか知らない。自分自身にとっては、Linux の有用性はキーボードの利用を要件としているために、あまり興味がない。
* Microsoft Windows が動作するノートパソコンについて Linux (Ubuntu) を動作させた環境について考える、という範囲から踏み出すことは、自分の実力に対しては手を広げすぎだろう。その範囲の中で多少勉強しておけば、その周辺での Linux の応用にも十分都合がよいはずである。
* コンピュータは、von Neumann architecture というものによって作られているらしい。コンピュータには、CPU があり、CPU は機械語を命令として動いている。機械語は assembly language にほとんど 1 対 1 に翻訳できるが、アセンブリ言語と C 言語とはかなり近い。優れた C 言語プログラマは、コンパイルされた機械語を disassemble したアセンブリを読むことをする。また、パフォーマンスを考える時にアセンブリ言語を考える。C 言語は、von Neumann architecture と近い。そのため、現在普通に流通しているコンピュータでパフォーマンスを出そうと思った時には、C 言語や C++ 言語で考えることが考えやすい。
* ソフトウェアを作ると、ほとんど必ずバグが生じる。世界は機械化によって生産性を得ているので、機械を動かしている制御プログラムにバグがあると、簡単に人が死んでしまう。そのため、見通しよくプログラムを設計し、バグをなるべく防ぐための努力が行われてきた。
* そのため、アセンブリ言語から、構造化プログラミング、オブジェクト指向プログラミング、関数型プログラミング、定理証明型プログラミングということが言われてきた。そこでは、単純なパフォーマンスは最優先ではない。
* オブジェクト指向プログラミングによる、ハードウェアの実装の抽象化については、Java と C# が成功を収めた。
* しかし、オブジェクト指向パラダイムとは別に、関数型パラダイムということも言われた。プログラムを純粋な関数に部品化し、それぞれにおいて入出力データの集合や相互関係を規制することが行われた。
* 関数型パラダイムについてかなり理想的に設計されたプログラミング言語として、Haskell がある。Haskell は、ラムダ計算であり遅延評価である？が、ラムダ計算であり遅延評価である場合、実際に計算が行われる順序はソースコードからかなりわかりにくい。人間にとって合理的な抽象化の発展ではあるものの、von Neumann architecture からかなり離れる。Haskell は、あまり流行っていない。
* そのように、ハードウェアの実態が von Neumann architecture である以上、C 言語が最も見通しがよい、という場合が残る。C、C++ だと、パフォーマンスを考えやすい場合が多く、またパフォーマンスを出しやすい場合が多い。
* von Neumann architecture + Linux + Bash + C + Qwerty
* Python 言語は、広く使われている。Python は C と違いインタプリタ言語である。つまり、ソースコードがそのまま動作する。このことは、単にコンパイルする手間がないという 1 点をとっても、大きな長所である。
* 個人的には、Python は、完全に整理された理想的な言語であるという印象が弱い。
* JavaScript 言語は、ウェブブラウザで広く使われている。JavaScript は、連想配列の木としてデータを持つ言語であり、前提の小さい柔軟な言語である。
* しかし、概ね前記の理由で、JavaScript や Python はハードウェアの実態に遠く、C 言語に比べてパフォーマンスを考えにくい。
* アセンブリ言語には、von Neumann architecture の実態が、手触りのある凹凸として表れていると考えられる。C 言語は、その凹凸を概ね感じられる言語だと考えることができる。Python だと、ぼんやり感じられる。Haskell だと、考えないとわからない。Java や C# だと、直接感じられるのは仮想マシンの感触であると考えることができる。
* アセンブリ言語は、プロセッサに依存している。C 言語では、コンパイラがそれを抽象化してくれる。そのため、上下を考えた上で最も汎用なプログラム表現というのは、C であるということになる。
* Neumann + Linux + Bash + C + Qwerty (NLBCQ) というのは、とても枯れたプラットフォームである。プラットフォームが安定していることの価値というのは、プログラミングを知っていなければわからない。優れた人々は、vendor lock-in の恐ろしさを知っている（と仮定しよう）。
* 若者は、若さに価値があると考え、新しいものを追いかけて村を出ていく。しかしやがて、価値があるように見えるが価値がないものを知り、結果的に、価値がないように見えたが価値があるものを知る。そうして古典に帰ってくる。その時にはすでに年老いている。
* Neumann や Linux や Bash や C や Qwerty という言葉を聞いた時、その言葉に故郷を感じることが好ましいだろう。他のプラットフォームを使うのは、便宜のためである。
* X Window System は、そこからはみ出している。本来、テキストエディタとコンパイラは、別のプログラムである。テキストエディタでファイルを編集し、テキストエディタを終了してから、テキストシェルでコンパイラを呼び出してコンパイルするのが、最も基本的な方法である。統合開発環境は、複雑すぎて、一般の人間をユーザにしてしまう。
* 統合開発環境が使えてもよいが、コマンドラインでコンパイルした経験があるほうがよい。Java が使えてもいいが、C と Java と Haskell を触った経験があるほうがよい。そうして、多忙で全て忘れてしまうなら、コマンドラインと C だけ覚えておくのが一番いいことが多い。
* gcc helloworld.c などとして C 言語プログラムをコンパイルすることは、人類が 1000 年前からやってきたことだ（嘘である）。他の全てのスタイルには、そこまでの実績がない。神々が Unix を創造した時から、C はそこにあった。
* 環境をターミナルに限ると、単純に対話的な処理のみでは、実現できない機能がある。その際、curses は便利である。しかし、curses を使わずに実現できる機能は、curses を使わずに実現すべきであると思われる。文字の色を変えるくらいはともかく、画面を更新することについての話である。
* bash でのキーボードでの操作は、汎用性があるが、最も効率的ではないことが多い。その際、curses で作ったプログラムならば、ユーザからの矢印キーの入力などを直接受け取れるので、キーボードを使った最善の効率を任意に実装できる。理論上はできる、が、自分で書くのは大変だろう。しかし、それをしたいなら curses というものを使えばよいということはわかった。
* 例えばどのような機能をどのように効率化できるだろうか？
* なお、ターミナルを使ったファイルシステムブラウザならば、すでにあるようであり、ここで目指しているものはそれと大きく違わないと思われる。しかしその特定のプログラムを使う予定はない。
