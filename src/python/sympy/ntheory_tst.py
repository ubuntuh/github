#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sympy
expr1 = sympy.factorint(1234567890, visual=True) # 素因数
sympy.pprint(expr1)
expr1 = sympy.divisors(1234567890) # 約数
sympy.pprint(expr1)
expr1 = sympy.divisor_count(1234567890) # 約数の個数
sympy.pprint(expr1)

