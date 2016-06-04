#!/usr/bin/env python3
# -*- coding: utf-8 -*-
def my_sum(n):
    return n * (n + 1) // 2
N = int(input())
values = list(map(int, input().split()))
values.append(-1)
answer = 0
increasing = []
for a in values:
    if not increasing:
        increasing.append(a)
        continue
    if a > increasing[-1]:
        increasing.append(a)
        continue
    answer += my_sum(len(increasing))
    increasing = [a]
print(answer)
