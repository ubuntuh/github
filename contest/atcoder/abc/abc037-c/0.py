#!/usr/bin/env python3
# -*- coding: utf-8 -*-
N, K = map(int, input().split())
a = list(map(int, input().split()))
answer = 0
for i in range(N):
    mul = min(i + 1, N - i, K, N - K + 1)
    answer += a[i] * mul
print(answer)
