# Common Lisp 入門 by 湯浅太一, 萩谷昌己

- １９８６年７月１８日第１刷
- １９８９年６月１５日第６刷

<!-- -->

- p. v - MacLisp, Interlisp, UCL Lisp, Standard Lisp
- UTI Lisp, Lisp 1.9
- p. vi - 「ソフトウェア危機」とまでいわれるほど、プログラムの生産性向上が大問題となっている昨今...
- p. vii - ZetaLisp, NIL, SPICE Lisp
- 情報処理学会記号処理研究会
- p. viii - Kyoto Common Lisp (KCL)
- p. 3 - 関数 function, 引数 argument
- floor は２つの数をうけとり、第１引数を第２引数で割った商と余りをかえす。
- p. 5 - 変数 variable
- p. 6 - 副作用、評価する。関数への引数は左から順に評価される。
- p. 8 - special form, 記号 symbol
- (set (quote x) 0) とすると変数 x に 0 を代入できる。これは (setq x 0) としてもよい。さらに、(psetq x expr1 y expr2) では、expr1 と expr2 が評価されてから代入が行われる。なお (quote x) は 'x と書いていい。setq にできて set ではできないこともある。
- p. 9 - x という式と (symbol-value 'x) という式の関係は、上に述べた (setq x 10) と (set 'x 10) の関係と同様である。
- p. 10 - (setq kakefu 31)
- しかし、システム変数以外の変数ははじめは空で、値を求めようとするとシステムにしかられる。つまり、エラーになる。エラーになったときのシステムの振る舞いはシステムによって異なるが、そのためにシステムがつぶれたり、計算機が火を吹いたりすることはない。
- :q
- 定数 constant, pi, nil, t
- p. 11 - 半径５の円の面積は (* pi (expt 5 2))
- p. 12 - (list 'we 'eat 'rice)
- 要素 element
- p. 14 - car (content of address part of register), cdr (content of decremental part of register), cons (construct), eval (evaluate)
- p. 18 - フォームとは式とみなされるデータのことである。
- 関数呼び出しのフォーム、スペシャル・フォーム、マクロ・フォーム、（フォームではないリスト）
- p. 20 - (macroexpand '(incf x))

## 2. 関数の定義

- p. 21 - プログラムを書くということは、基本的には、自分で関数を定義するということである。
- p. 25 - このことを、変数 x を 4 にバインド (bind) するとか、x が 4 にバインドされるとかいう。
- p. 26 - スコープ scope, 局所変数 local variable, 大域変数 global variable
- p. 33 - nil 以外のどんなデータも「真」（正しい）をあらわす。
- 条件の真偽を決定するために使われる関数を**述語**とよぶことがある。
- t は true の "t" である。
- p. 34 - 述語 predicate
- p. 35 - if 式のように、条件の真偽によって次になにをするかが左右される式を**条件式**とよび、条件を表す式を**論理式**とよぶことがある。
- p. 39
