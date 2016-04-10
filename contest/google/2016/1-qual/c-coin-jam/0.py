#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import itertools
import sympy as sy
class MyRange:
    def __init__(self, length):
        self.length = length
        del length
        self.short_length = self.length - 2
        range_ = range(0, 2 ** self.short_length)
        self.iter_ = iter(range_)
    def __iter__(self):
        return self
    def __next__(self):
        i = next(self.iter_)
        str0 = '1{0:0' + str(self.short_length) + 'b}1'
        str1 = str0.format(i)
        int_ = int(str1)
        return int_

for i, n in zip(itertools.count(), MyRange(10)):
    is_prime = sy.isprime(n)
    prime_factors = sy.primefactors(n)
    print('i = {0}, n = {1}, is_prime = {2}, prime_factors = {3}'.format(i, n, is_prime, prime_factors))
