#!/usr/bin/env python
# -*- coding: utf-8 -*-
from sympy import *
x, y, z = symbols('x y z')
expr1 = Integral(sqrt(1/x), x)
pprint(expr1)
pprint(expr1, use_unicode=False)
