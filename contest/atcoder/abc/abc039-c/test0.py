#!/usr/bin/env python3
# -*- coding: utf-8 -*-
def f0(string):
    result = 0
    length = len(string)
    for i in range(length):
        character = string[0]
        string = string[1:]
        result *= 2
        if character == 'B':
            result += 1
    return result
string0 = 'WBWBWWBWBWBW'
string1 = string0 * 2
list0 = []
for i in range(12):
    string2 = string1[i:i + 12]
    if string2[0] == 'B':
        continue
    print(string2)
    result = f0(string2)
    print(result)
    list0.append(result)
list1 = ['Do', 'Re', 'Mi', 'Fa', 'So', 'La', 'Si']
list2 = list(zip(list0, list1))
print(list(list2))
list3 = sorted(list2)
print(list3)
