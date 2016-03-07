# Gnu Assembler

* https://en.wikipedia.org/wiki/Calling_convention
* https://en.wikibooks.org/wiki/X86_Assembly
* https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture
* https://en.wikibooks.org/wiki/Category:X86_Disassembly
* http://stackoverflow.com/questions/8510333/x86-64-assembly-linux-system-call-confusion
* http://www.mztn.org/index.html
* http://blog.livedoor.jp/hiroumauma/archives/1385003.html
* http://capm-network.com/?tag=GAS
* http://www.cs.is.noda.tus.ac.jp/~mune/master/09/x86.pdf
* http://wisdom.sakura.ne.jp/programming/asm/index.html
* http://homepage1.nifty.com/herumi/
* http://www.ibm.com/developerworks/jp/linux/library/l-gas-nasm.html

### 2016-02-01 Mon

# コンパイル方法

* Ubuntu でアセンブリをコンパイル（アセンブル）するためには、拡張子 .s としたテキストファイルにアセンブリコードを記述し、gcc helloworld.s などとしてコンパイルすればよい。
* gcc は c 言語のプログラムをコンパイルする際にも使われるコマンドであるが、与えられたファイルの拡張子から、実際にどのツールでコンパイルするか自動的に推定している。アセンブリをコンパイルする際には、gcc の背後で、as というファイル名のプログラムが動作している。これは正式には、GNU Assembler と呼ばれるプログラムである。
* Linux のカーネルをアセンブルする際にも、as (GNU Assembler) は使われている。
* gcc で C のプログラムをコンパイルする時も、一旦 アセンブリが生成されて、as でアセンブルされているらしい。gcc helloworld.c とするのは、gcc -S helloworld.c としてから gcc helloworld.s とするのと同じらしい。

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

# objdump

* objdump コマンドが、逆アセンブルのための標準的なコマンドであるらしい。
* objdump -d a.out や objdump -S a.out として逆アセンブルできる。
* 例えば gcc -g helloworld.c などとコンパイルしておくことで、実行ファイルに、デバッグのための情報が追加され、objdump -S a.out とした時に並列に表示してもらえる。また、objdump -S -l a.out とすると、ソースファイルとその行数が表示される。
* 特定の関数のみ逆アセンブルする簡単な方法はない。

# gcc -m32

* 64 bit の環境で 32 bit のためのアセンブリをそのままアセンブルしようとすると、アセンブルエラーになることが多い。
* gcc -m32 helloworld.s とすればよい。
* しかし、デフォルトでは、自分の環境のためのライブラリしかインストールされていないことが普通であり、そのためにこれに失敗する。
* sudo apt-get install gcc-multilib とすればよい。
* こうすることで、64 bit 環境でも 32 bit のためのアセンブリを、-m32 オプションを使ってアセンブルできるようになる。

# 64 bit アセンブリ

* 64 bit のアセンブリというのはあまり一般的でないっぽい。
* 多くの場合必要なかったり、実行ファイルが大きくなったりするようである。

# 呼出規約

* calling convention というものがある。
* 32 bit のシステムコールを呼び出す際には　eax に関数の番号、ebx、ecx、edx に引数を入れて 0x80 で inturrupt すればよいらしい。
* 一方で、64 bit の場合は、もう少し覚えにくい。Wikipedia の x86 calling convention にあるように、次のような約束になっている。
* The first six integer or pointer arguments are passed in registers RDI, RSI, RDX, RCX, R8, and R9, while XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6 and XMM7 are used for floating point arguments. For system calls, R10 is used instead of RCX. As in the Microsoft x64 calling convention, additional arguments are passed on the stack and the return value is stored in RAX.
* RDI、RSI、RDX、RCX、R8、R9 というのはつまり、R7、R6、R2、R1、R8、R9 である。システムコールについては R1 ではなく R10 が使われるということになる。少し規則性があるが、どちらにせよわかりにくい。
* 汎用レジスタの名前には意味があるのだろうか？
* R0 から R7 までは名前があって、公式ドキュメントでもそちらが使われているらしい。また、GNU Assembler でアセンブルする際も、RAX を R0 と呼ぶと受けつけてくれない。
