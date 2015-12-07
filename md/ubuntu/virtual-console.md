# Virtual Console

- Ubuntu においては、デフォルトで、仮想コンソール (virtual consoles) というものが用意されている。
- 仮想コンソールは、デフォルトで GUI ではなく CUI であるものが、tty1 から tty6 まで 6 つ用意されている。
    - tty とは teletypewriter という意味である。teletypewriter というのは歴史的なハードウェアである。
- 例えば、Ctrl+Alt+F1 で tty1 を表示できる。デフォルトの GUI 環境に戻ってきたい場合には、Ctrl+Alt+F7 を押せばよい。
    - tty2 から tty6 までも Ctrl+Alt+F2 などとして同様に移動できる。
    - 特に、CUI 環境においては、単に Alt+F1 などとすることで他に移動できる。また Alt+Left や Alt+Right でも移動できる。
- tty1 などの virtual console では、デフォルトでは、日本語を入力することができないのみならず、表示することもできない。
- 普通に GUI のみ使っていて virtual console を活用していない状態では、/sbin/agetty が 6 つ動いていて、ユーザのログインを待っている。このことは、ps a | grep getty などとして確認できる。

