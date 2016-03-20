    # 最小のプログラム？です。システムコール exit(0) を呼び出して終了するだけです。
    # assembler directive である .global を用いて、記号 _start をリンカプログラムである ld に対して露出する。一般に assembler directive にはドットが前置される。
    .global _start
    # .text ディレクティブを用いて、ここが text セグメントであることを言う。text セグメントは data セグメントと異なりデータの変更ができない領域であり、普通、プログラムコードはここに配置される。
    .text
    # ここのアドレスにラベル _start を割り当てる。
_start:
    # CPU はレジスタに値を保持することができる。
    # 64 bit の汎用レジスタとして r0 別名 rax があり、その下位 32 bit を eax と呼び、その下位 16 bit を ax と呼び、その下位 8 bit を al と呼ぶ。ここでは 32 bit である eax を使う。レジスタを表す際には % を前置する。
    # ここでは、eax に値 1 を格納したい。即値には $ を前置し、$1 などと表す。
    # mov 命令は、一般に値をコピーする命令である。8 bit は b、16 bit は w、32 bit は l、64 bit は q で表し、扱いたい大きさを命令の名前に後置する。ここでは 32 bit を扱いたいので movl とする。
    # movl $1, %eax で、eax が 1 になる。1 は、システムコール exit を表す。
    movl    $1, %eax
    # 同じく 32 bit の汎用レジスタである ebx に、0 を入れる。呼び出したい関数の第 1 引数を ebx に入れるのである。exit(0) として機能させるためである。
    movl    $0, %ebx
    # 16 進数の 80 を引数として、割り込み (inturrupt) 命令を行う。これは、システムコールを呼び出すための古典的な方法である。
    # システムコールを呼び出すには、他にも方法があり、意味が異なる。しかし、この基本的な方法から教えている資料が多い。
    int     $0x80
    # これによって、eax と ebx が参照され、exit(0) が実行された。