#!/usr/bin/env python3
# -*- coding: utf-8 -*-
length, num_queries = map(int, input().split())
array = [0] * length
for _ in range(num_queries):
    left, right, value = map(int, input().split())
    left -= 1
    array[left : right] = [value] * (right - left)
for value in array:
    print(value)
