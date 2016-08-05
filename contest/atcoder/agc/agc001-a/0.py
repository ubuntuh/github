#!/usr/bin/env python3
# -*- coding: utf-8 -*-
N = int(input())
Ls = list(map(int, input().split()))
sorted_ = sorted(Ls)
list_ = []
for i, x in enumerate(sorted_):
    if i % 2 == 0:
        list_.append(x)
sum_ = sum(list_)
print(sum_)
