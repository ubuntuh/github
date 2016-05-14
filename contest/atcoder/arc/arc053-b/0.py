#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from collections import Counter
string = input()
counter = dict(Counter(string))
num_pairs = 0
num_no_pairs = 0
for key in counter:
    num_pairs += counter[key] // 2
    num_no_pairs += counter[key] % 2
answer = 0
if num_no_pairs >= 1:
    answer = 2 * (num_pairs // num_no_pairs) + 1
else:
    answer = 2 * num_pairs
print(answer)
