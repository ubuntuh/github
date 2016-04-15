# Aaron Meurer's SymPy Blog

- https://asmeurersympy.wordpress.com/

### 2009-04-22 First Post!

- Well, I got accepted into the Google Summer of Code program of 2009.
- 2009 年の Google Summer of Code に申し込んで、私、採用されました。
- I will be working on SymPy, a computer algebra system written and run in Python.
- SymPy について作業する予定です。SymPy ていうのは、Python で書かれ Python で動作する、数式処理システム。
- I will be working on building on ordinary differential equation engine for it, as its present capabilities are very limited.
- 私は、SymPy の常微分方程式エンジンを開発します。現在のものの機能はとても限られているからね。
- You can look at my application abstract.
- 私の申請書の概要はここで見られます。
- SymPy requires that I blog about my work at least once a week, so here it is.
- SymPy は、私が私の作業について週に一回以上ブログすることを要求しています。なのでこれがそれです。
- More will be posted here later.
- これからもっと投稿していくよ。
- p
- Originally I started this blog on blogger, but I think WordPress will be a little better.
- このブログは最初、blogger で初めようと思ったのだけど、WordPress のほうがいいなと思った。
- Namely, it seems to support plugins, so I can insert LaTeX code much easier.
- というのも、WordPress ではプラグインが使えるから、LaTeX コードをずっと簡単に挿入できる。
- It would seem that only blogs not hosted at wordpress.com support plugins.
- <- 取り消し。wordpress.com でホストされているのではないブログについてだけプラグインが使えるみたいだ。
- So I think I will just use LaTeXiT and do it manually.
- なので、LaTeXiT を使って手作業でそれは行うことになると思う。
- Oh well.
- ああ、そう。
- Anyway here is the Divergence Theorem, which nicely show both mathematical beauty and LaTeX beauty.
- とりあえずここに発散定理を貼るよ。発散定理だと、数学的な美しさと LaTeX の美しさが表れるね。

### 2009-04-26 Git Tutorial

- So I was browsing the Google Open Source Blog, when I found a link to this Git Tutorial.
- それで、Google Open Source Blog を見ていたら、この Git チュートリアルへのリンクを見つけたよ。
- I wish I had found this a month ago when I started learning Git.
- Git を勉強しはじめた頃に、つまり一か月前に見つけていたらなあと思う。
- SymPy only has a very basic tutorial for Git.
- SymPy の Git の説明はごく基礎的なことにとどまる。
- Their main tutorial is still written for Mercurial, which they used until recently.
- バージョンコントロールシステムについての SymPy での説明はまだ主に Mercurial についてのものだ。彼らは最近まで Mercurial を使っていたからである。
- p
- Anyway, I have been reading the tutorial, and so far it is awesome, so I thought it would make a good post here.
- それで、その見つけたチュートリアルを読んでる。今のところ、素晴らしいものだという印象である。だからここにこの投稿をするのもいいと思った。

### 2009-05-08 My GSoC Proposal

- I have copied my proposals over to the SymPy Wiki and formatted them so that they look nice (including LaTeX for the formulas).
- 私の提案をコピーして SymPy のウィキに表示した。数式の LaTeX を含めて、綺麗に見えるように整えた。
- I included both the Portland State University proposal, which was accepted (at the top), and the Python Software Foundation proposal, which was nearly identical, but was not accepted.
- （一番で）受け入れられた、ポートランド州立大学への提案を含めた。それと、ほとんど同じものだけど合格しなかった、Python Software Foundation の提案も含めた。
- I did this mainly for myself so I can easily find my timeline during the summer, but if anyone wants to see what my proposal looked like, here it is.
- SymPy Wiki にそれを載せたのは、主に自分のため、つまり、この夏の間、自分のタイムラインを簡単に見つけるためだ。でも、もし誰か、私の提案がどんなのか見たかったら、これで見れる。
- Note that I am pretty sure that the timeline on the proposal will not be the same as what I will actually do (e.g. I have learned much less about systems of ODEs, than I expedted, and I have learned about a couple new symbolic methods).
- ちなみに、その提案書に書かれた予定表と、私が実際にすることが同じにならないであろうことは、自覚しているからね。例えば、私は期待したほど、常微分方程式について学ばなかったし、一方で、いくつかの新しい記号計算の方法を習った。
- This link is here.
- これがリンクだよ。（リンク切れ）

### 2009-05-16 Work started --- Exact Differential Equations

- I have decided to start working on my project, even though it is a week early, since I am finished with school and have nothing better to do.
- 私のプロジェクトの作業を開始することにした。まだ一週間早いけどね。だって、学校が終わって、他により優先すべきこともないから。
- I also like the idea of getting ahead.
- それに私は物事を早め早めにやってしまうのが好きだ。
- I am pushing everything to my github account.
- 私は、全てを、私の github アカウントに上げている。
- So far, I have implemented exact differential equations, which are cake (i.e., they took me about an hour to code up).
- すでに、完全微分方程式を実装したよ。簡単だった（一時間くらいでプログラムできた）。
- ...
