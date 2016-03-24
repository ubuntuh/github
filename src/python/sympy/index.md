# sympy

- sudo apt-get install sympy

### 2016-03-24 Thu

- subs で Evaluation=False にしたいが方法が不明である。不可能かもしれない。
- 簡単な再帰的な関数、例えば階乗を求める関数を sympy の式の上で実装したいが、方法が不明である。不可能かもしれない。sympy.Function を継承したクラスを定義する方法は可能だが、面白くはない。
- 例えば f(x) = Piecewise((1, Eq(x, 1)), (x * f(x - 1), True)) みたいなことがしたかった。