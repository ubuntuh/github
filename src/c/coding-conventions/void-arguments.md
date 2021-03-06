# void arguments

### 2016-02-28 Sun

- C 言語によるプログラミングについて例えば、void f() と書くよりも void f(void) と書け、と言われることがある。そのような、引数として void を明示するしない、という論点について考えたい。
- ANSI C という標準が定められるよりも以前、C 言語における関数宣言は、後のように厳格ではなかった。というのも、void f(); という関数宣言は、関数名と返り値の型を示しているのであって、引数の個数と型は任意であることを示している。ANSI C において C 言語は拡張され、引数について宣言されるようになった。
    - 引数について定義しない（古い形式の）関数宣言を前方宣言と言い、引数について定義する（新しい形式の）関数宣言をプロトタイプ宣言と言う。←誤り。どちらも前方宣言。
- その際、後方互換性が考慮された。
- そのため今も、void f(); という関数宣言には、引数がないという意味はない。引数がないということは例えば、void f(void); として表す。
- しかし、C++ 言語では、void f() は、void f(void) という意味である。C++ 言語の方が、仕様が端的に整理されていると言える。
- C 言語では、関数の型がわからない時には int と仮定する。
    - そのため、int 型の値を返す関数は、後方で定義されていても関数宣言せずに呼び出せる。しかし例えば gcc では、implicit declaration of function といった警告 (warning) が出る。

#### -

- 例えば C 言語で、void f() { puts("a"); } として関数 f を定義したとしよう。この関数は、f(0); などと呼び出せる。なぜなら、定義における「f()」は、引数が任意だという意味だからである。
- つまり、引数に void を明示するかどうかという問題は、前方宣言に限らない。
- しかし、引数に名前がないから普通には引数にアクセスできないかもしれない。
- この例で、定義を変更して、「f(void)」と定義したならば、f(0); といった呼び出しは、コンパイルエラーになる。これは好ましい。なぜなら、引数があると思って引数つきで呼び出した間違いを、コンパイル時に検出できるからである。

#### -

- main 関数の標準的な引数は、int main(int argc, char **argv) { ... というものであるというイメージがある。
- int main() { ... という定義は、C 言語においては引数が任意だと言っているのだから、これは上の場合を含んでいると考えることができ、その意味で、これがコンパイルできることはわかる。
- 一方で、int main(void) { ... という定義でもコンパイルでき、動作する。これは不思議である。とは言っても、C++ 言語においては、int main() { ... はこの意味である。
- また、これらは全て gcc で行ってみた結果だが、int main(int argc, char **argv, int a) { ... という、つまり標準的な引数のあとに無駄な引数を追加した定義でも、コンパイルでき動作するようである。argc、argv には正常にアクセスできる。不思議である。
- C 言語上で考えると、この関数を呼び出す側のコードが、変更を迫られる気がする。引数が 3 つの関数を、引数 2 では呼び出せない気がする。

#### -

- C++ では、f() は f(void) の意味である。わかりやすい。
- しかし、C++ で実装した関数を C のコードから呼び出す場合があるなら、f(void) となければ、C で f() とした時と同様の損失があるらしい。

#### -

- 常に f(void) の形式を用いることが安全であると思われる。
- しかし、int main() とか int f() といったコードを見る機会は多い気がする。
- f() といった形式には長所がある。書くのが楽で、読むのも楽である。
- 実際、f() と書いたことによって生じる損失は、問題にならないのかもしれない。
- 関数のプロトタイプについては、引数の数と型を、f(void) などと示し、定義する部分においては f() { ... などと実装することが、合理的で一般的な落とし所なのかもしれない。
- しかし、f() の () が、(void) ではなく任意の引数らを表わしている、（C では）表しかねない、と思うと、少し気持ちが悪いような気もする。
- C での int main() { ... は、引数の定義を省略しているようにも見えるし、C++ での int main() { ... は、引数は void だと定義しているように見える。しかし、引数の定義を省略しているつもりで、int main() { ... を C++ としてコンパイルしていたならば、それはよく理解していないということになるだろう。
- main 関数の引数の型を void としても gcc でコンパイルできるようである。C99 以降ではそれが正式であり、一方 C++ (g++) では不正だという。私が main が int 以外を返すプログラムを書く必要性は普通発生しないだろうと思われる。hosted environment と freestanding environment という概念がある。
- 引数の型のデフォルトは int なので引数の型を示さずに main() { ... と書いてもコンパイルできる。しかし警告は出る。

#### -

- ところで、古い形式 (?) で、void f(value) int value; { ... などと、引数の識別子の後で型を指定する書き方がある。
- 引数の型もデフォルトで int であるので、int なら型を指定しなくてもコンパイルできるようである。しかし警告は出る。
- このように眺めると、初期の C では型はデフォルトで int としたという印象を強く感じる。それは合理的な仕様であるように思う。現代では普通、int 型も毎回明示するだろう。その言わば仕様あるいはスタイルの変更は、ある合理的からある合理的への、多少の決断を伴うジャンプであったようにも感じられる。int 型が明示されていなければ警告を出すようにしたことで、int 型でないのに型を指定し忘れた誤りを、コンパイル時に検出できるようになった。
- このような、pre-ANSI C などと呼ばれるような論点は、ほとんどの場合、自分自身は現代的なスタイルのみ使えばよいのだろうと思われる。しかし、読む時に一々驚かないほうが便利である。

#### -

- 結局、今一つ、結論が出ない。
