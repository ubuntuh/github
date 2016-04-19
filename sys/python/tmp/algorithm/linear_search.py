#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""線型探索。linear search とも sequential search とも言う。"""

def linear_search(key, list_):
    index = 0
    list_length = len(list_)
    while index < list_length:
        if list_[index] == key:
            return index
        index = index + 1
    return None

def linear_search_sentinel(key, list_):
    """番兵を用いた線型探索。"""
    list1 = list(list_)
    list1.append(key)
    sentinel_index = len(list1) - 1
    index = 0
    while True:
        if list1[index] == key:
            result = index
            break
        index = index + 1
    if result == sentinel_index:
        return None
    return result

def linear_search_recursive(key, list_, acc):
    """再帰的な呼び出しを用いた線型探索。"""
    if len(list_) == 0:
        return None
    if list_[0] == key:
        return acc
    else:
        return linear_search_recursive(key, list_[1:], acc + 1)
            
if __name__ == '__main__':
    list_ = [2, 4, 6, 8]
    result = linear_search(6, list_)
    assert result == 2
    result = linear_search(5, list_)
    assert result is None
        
