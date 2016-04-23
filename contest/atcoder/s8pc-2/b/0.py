#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# 間違っている。
n, q = list(map(int, input().split()))
print('n = ' + str(n))
numbers = {}
numbers['range'] = (1, n)
numbers['deads'] = []
numberss = [numbers]
print('q = ' + str(q))
for i in range(q):
    print('i = ' + str(i))
    a = int(input())
    print('a = ' + str(a))
    new_numberss = []
    for numbers in numberss:
        new_numbers = {}
        new_numbers['range'] = (1, numbers['range'][1] // a)
        new_numbers['deads'] = []
        deads = numbers['deads']
        for dead in deads:
            if dead % a == 0:
                new_numbers['deads'].append(dead / a)
            else:
                new_numbers['deads'].append(dead)
        numbers['deads'].append(a)
        new_numberss.append(new_numbers)
    numberss.extend(new_numberss)
    print(numberss)
answer = 0
for numbers in numberss:
    if 1 not in numbers['deads']:
        answer += 1
print(answer)
            
