# as

* https://en.wikipedia.org/wiki/Calling_convention
* https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture
* http://stackoverflow.com/questions/8510333/x86-64-assembly-linux-system-call-confusion
* http://www.mztn.org/index.html
* http://blog.livedoor.jp/hiroumauma/archives/1385003.html
* http://capm-network.com/?tag=GAS
* http://www.cs.is.noda.tus.ac.jp/~mune/master/09/x86.pdf

### 2016-02-01 Mon

# コンパイル方法

* Ubuntu でアセンブリをコンパイル（アセンブル）するためには、拡張子 .s としたテキストファイルにアセンブリコードを記述し、gcc helloworld.s などとしてコンパイルすればよい。
* gcc は c 言語のプログラムをコンパイルする際にも使われるコマンドであるが、与えられたファイルの拡張子から、実際にどのツールでコンパイルするか自動的に推定している。アセンブリをコンパイルする際には、gcc の背後で、as というファイル名のプログラムが動作している。これは正式には、GNU Assembler と呼ばれるプログラムである。
* Linux のカーネルをアセンブルする際にも、as (GNU Assembler) は使われている。

# コメント

* 複数行のコメントアウトは、/* ... \*/ で行われる。
* 1 行のみコメントするためには、# などがあるが、具体的には、アセンブル対象となるアーキテクチャによって異なる。
* 共通させたい場合、1 行コメントについても /* ...\*/ を使えばよいのだろうか？　それとも、アセンブリにおいては、複数のアーキテクチャに同時に対応したいという必要性はないのだろうか？

# AT&T syntax

* アセンブリの記法には大きく 2 種類あって、AT&T syntax と Intel syntax と呼ばれる。
* Linux で逆アセンブルをする際には gdb コマンドや objdump コマンドが使われるが、これらは標準で AT&T syntax を出力する。ただし、GNU が提供するこのようなプログラムの全てで、オプションで Intel syntax を用いることも問題なくできる。
* しかしながら、Linux カーネルのソースコードで使われているのは AT&T syntax であり、Linux では歴史的に AT&T syntax であると言える。一方で、Microsoft Windows の世界では、Intel syntax の方が広く用いられてきた。
* 機能としてはほとんど同等であるらしい。
* オプションを渡すのは面倒なので、AT&T syntax を贔屓して使っていけばいいのかなと思う。
* 読む際には、ストレスなくどちらも読めることが理想的なのだろう。
