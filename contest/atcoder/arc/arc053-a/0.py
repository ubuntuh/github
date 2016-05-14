#!/usr/bin/env python3
# -*- coding: utf-8 -*-
height, width = map(int, input().split())
answer = 0
for y0 in range(height):
    for x0 in range(width):
        for y1 in range(y0, height):
            for x1 in range(x0, width):
                if x1 - x0 + y1 - y0 == 1:
                    answer += 1
print(answer)
