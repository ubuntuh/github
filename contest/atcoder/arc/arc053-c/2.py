#!/usr/bin/env python3
# -*- coding: utf-8
# Accepted.
num_magics = int(input())
downs = []
ups = []
for _ in range(num_magics):
    up, down = map(int, input().split())
    if up < down:
        downs.append((up, down))
    else:
        ups.append((up, down))
downs = sorted(downs, key=lambda x: x[0])
ups = sorted(ups, key=lambda x: x[1], reverse=True)
max_ = current = 0
for up, down in downs + ups:
    current += up
    max_ = max(max_, current)
    current -= down
print(max_)
