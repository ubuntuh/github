# Zero-based or One-based Indexing

### 2016-03-20 Wed

- 10 個の要素からなる配列を a[0] から a[9] で表す方法と、a[1] から a[10] で表す方法がある。それぞれ zero-based indexing と one-based indexing と言う。
- C 言語では、デフォルトで zero-based である。しかし、要素を 1 つ多く取っておけばその僅かなコストで one-based としても扱える場合が多い。
- one-based が有用な場合もあるように思う。
- zero-based と one-based の長所と短所を整理したい。
- / と % の仕様は変更できないことが多いだろう。a / 10 は 10 から 19 について 1 である。a % 10 は 9 について 9 であり 10 について 0 である。これについて zero-based は好ましい。
- modulo operation。
- 何もかも zero-based で押し通せるだろうか？
- pointer の計算についても zero-based がわかりやすいらしい。
- 以下のものがあるがちゃんと読んでいない。
- Wikipedia - Zero-based numbering
- Wikipedia - Index notation （添字表記法）
- 1982 - Edsger W. Dijkstra - Why numbering should start at zero
- 物を数える時は普通、1 個、2 個と言う。0 個というのは普通、無いことに対応する。
- 水が 1 liter、2 liters と言う。1 liter ずつ袋に分けると袋が 2 個である。one-based だと個数と量が対応するようである。
- zero-based では 0 が [0, 1) を表わしており、one-based では 1 が (0, 1] を表わしていると考えることができるかもしれない。
- for (int i = 1; i <= n; ++i); と書くことには魅力がある気がする。なぜなら、i は実際 1 から n にまでなるのに対して、そこに 1 と n そのものが表れているからである。
- むしろ one-based で押し通せないだろうか？

