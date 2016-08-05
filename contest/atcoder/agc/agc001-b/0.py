#!/usr/bin/env python3
# -*- coding: utf-8 -*-
N, X = list(map(int, input().split()))
sum_ = X
prev = X
next = N - X
i = 0
while True:
    num = prev // next
    if i == 0:
        sum_ += 2 * num * next
    elif i % 2 == 1:
        sum_ += 2 * num * next - next
    else:
        sum_ += 2 * num * next - next
    mod_ = prev % next
    if mod_ == 0:
        break
    sum_ += next
    prev = next
    next = mod_
    i += 1
print(sum_)
