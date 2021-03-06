#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# http://docs.sympy.org/latest/tutorial/intro.html
from sympy import *
init_printing()
print('# Python の記号計算ライブラリである sympy について、公式チュートリアルを参考にデモを行います。')
nu = Symbol('nu')
t = Symbol('t')
x = Symbol('x')
y = Symbol('y')
z = Symbol('z')
print('# 変数 expr に式 x + 2 * y を代入します。')
print('\t> expr = x + 2 * y')
expr = x + 2 * y
pprint(expr)
print('# ここから x を引けば自動的に x の項が消去されます。')
print('\t> expr - x')
pprint(expr - x)
print('# また、x を掛けると、展開されずに保持されます。')
print('\t> x * expr')
pprint(x * expr)
print('# 関数 expand を使って式を展開できます。')
print('\t> expanded_expr = expand(x * expr)')
expanded_expr = expand(x * expr)
pprint(expanded_expr)
print('# また、関数 factor を使って、因数を得ることができます。')
print('\t> factor(expanded_expr)')
pprint(factor(expanded_expr))
print('# 微分できます。')
print('\t> diff(sin(x) * exp(x), x)')
expr = sin(x) * exp(x)
pprint(diff(expr, evaluate=False))
pprint(diff(expr, evaluate=True))
print('# 不定積分。')
print('\t> integrate(exp(x) * sin(x) + exp(x) * cos(x), x)')
expr = exp(x) * sin(x) + exp(x) * cos(x)
pprint(Integral(expr, x))
pprint(Integral(expr, x).doit())
print('# 定積分。')
print('\t> integrate(sin(x ** 2), (x, -oo, oo))')
expr = sin(x ** 2)
pprint(Integral(expr, (x, -oo, oo)))
pprint(Integral(expr, (x, -oo, oo)).doit())
print('# 極限。')
print('\t> limit(sin(x) / x, x, 0)')
expr = sin(x) / x
pprint(Limit(expr, x, 0))
pprint(limit(expr, x, 0))
print('# 方程式 x ** 2 - 2 = 0 の（x についての）解を得る。')
print('\t> solve(x ** 2 - 2, x)')
expr = x ** 2 - 2
pprint(solve(expr))
print("# 微分方程式 y'' - y = e ** t を解く。")
expr = Eq(y(t).diff(t, t) - y(t), exp(t))
pprint(expr)

print(expr)
latex(expr)
print(latex(expr))
from IPython.display import display
display(expr)

pprint(dsolve(expr))
print('# 行列から固有値を得る。')
expr = Matrix([[1, 2], [2, 2]])
pprint(expr)
pprint(expr.eigenvals())
print('# ベッセル関数 J_v(z) を球ベッセル関数に書き直す。')
expr = besselj(nu, z)
pprint(expr)
pprint(expr.rewrite(jn))
