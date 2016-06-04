#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from itertools import product
left = list(map(int, input().split()))
right = list(map(int, input().split()))
is_found = False
for left_height, right_height in product(left, right):
    if left_height == right_height:
        is_found = True
        break
if is_found:
    print('YES')
else:
    print('NO')
