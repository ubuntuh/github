#!/usr/bin/env python3
# -*- coding: utf-8 -*-
left = list(map(int, input().split()))
right = list(map(int, input().split()))
is_found = False
for left_height in left:
    for right_height in right:
        if left_height == right_height:
            is_found = True
if is_found:
    print('YES')
else:
    print('NO')
