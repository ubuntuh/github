#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import itertools
class Node:
    pass
class Point:
    def __init__(self, x):
        self.x = x
    def __str__(self):
        return str(self.x)
def make1DTree(l, r):
    global np
    if not (l < r):
        return None
    # sort.
    mid = (l + r) // 2
    t = np
    np += 1
    T[t].location = mid
    T[t].l = make1DTree(l, mid)
    T[t].r = make1DTree(mid + 1, r)
    return t
def find(v, sx, tx):
    x = P[T[v].location].x
    if sx <= x and x <= tx:
        print(P[T[v].location])
    if T[v].l is not None and sx <= x:
        find(T[v].l, sx, tx)
    if T[v].r is not None and x <= tx:
        find(T[v].r, sx, tx)
P = []
T = []
xs = [1, 3, 5, 6, 10, 13, 14, 16, 19, 21]
for i, x in zip(itertools.count(), xs):
    P.append(Point(x))
    T.append(Node())
n = len(xs)
np = 0
make1DTree(0, n)
find(0, 6, 15)
