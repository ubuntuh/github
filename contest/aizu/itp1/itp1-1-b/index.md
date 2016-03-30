# ITP1_1_B: X Cubic

### 2015-12-24 Thu

- 入力の 3 乗を返す。
- 定義域は整数としか示されていないが、オーバーフローは考えなくてよいようだ。
- 入出力を行うのに、iostream の std::cin や std::cout を用いる方法と、cstdio (stdio.h) の scanf や printf を使う方法があるようだ。
- scanf や printf の方が高機能な気がするが、cin や cout を使う必要があるのだろうか？
- C++ で、関数のプロトタイプを宣言するのが煩わしい。
- c++ では、C と異なり、math.h をインクルードするのではなく、cmath をインクルードして、std::pow などと参照するのが、行儀がよいらしい。しかし実際に使ってみると、cstdio の printf にしろ cmath の pow にしろ、std:: をつけなくても使えるようだ。
- StackOverflow - Implementations of the C++ standard library are permitted to declare C library functions in the global namespace as well as in std. Some would call this a mistake, since (as you've found) the namespace pollution can cause conflicts with your own names. However, that's the way it is, so we must live with it.
- グローバルなネームスペースに露出している識別子を std 名前空間に押し込める簡単な方法はないようだ。
- つけなくてもよい std:: をつけて書いてもいいのだが、書かなくてもエラーが出ない以上、必ず完全にはいかないところが気味が悪い。
