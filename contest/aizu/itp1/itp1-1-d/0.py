#!/usr/bin/env python3
# -*- coding: utf-8 -*-
S = int(input()) # 0 <= S < 86400 = 24 * 60 * 60
h = S // (60 * 60)
m = (S // 60) % 60
s = S % 60
print(h, m, s, sep=':')
