# C++ 基礎講座

- 1994 年 2 月 1 日 初版発行
- 1995 年 8 月 21 日 第 1 版第 5 刷発行
- The C++ Primer---A Gentle Introduction to C++ by M. T. Skinner
- 春木良且 (Yoshikatsu Haruki) 訳。1956 年生まれ。

## 第 1 章 C++ の概要

- p. 15 のコードについて。`#include <iostream.h>` の .h を外さないと動かない。それと、次の行に `using namespace std;` と挿入しないと動かない。
- p. 16 - 定義と宣言は、実際に主記憶に領域を割り当てるかどうかによって区別されます。定義では領域が割り当てられますが、宣言では割り当てられません。
- 実引数 (argument)
- 演算子 "<<" は、出力ストリームの演算子であり、右オペランドの値を左オペランドが表すストリームに書き込んでそのストリームを返す。
- "<<" は左結合である。実際、`(cout << "hello, world") << endl;` は正しいが `cout << ("hello, world" << endl);` はコンパイル時エラーである。
- endl は、操作関数 (manipulator function) と呼ばれる特殊な関数名です。
- 文は必ず関数の中で指定しなければなりません。このように、文を関数の中に閉じ込めることを、**カプセル化** (encapsulate) といいます。
- suffix = extension
- C++ のソースファイルの拡張子は色々である。.cpp が無難であるようだ。ヘッダファイルを .h ではなく .hpp とすると便利だという話がある。
- link = combine
- Borland C++, Microsoft C/C++, Microsoft Visual C++, UNIX, GNU C++, SUN C++
- 擬似コード (pseudo code)
- terminal で EOF を入力するのは、Windows では Ctrl+Z だが、Unix-like では Ctrl+D。Unix-like で Ctrl+Z するとプログラムを suspend させ、jobs で確認、fg で回復できる。