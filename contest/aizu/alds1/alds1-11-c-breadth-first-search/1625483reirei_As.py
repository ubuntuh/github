#!/usr/bin/python3
# http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1625483
def find(id, V, d, dist): # 頂点 id を距離 d とする。また id の子らについて再帰的に処理する。隣接リスト V は変更されない。dist はグローバル変数である。
    i = id - 1
    dist[i] = d
    for v in V[i]: # 頂点 i の全ての子について。
        if dist[v - 1] == -1 or dist[v - 1] > d + 1: # 子の距離を更新すべき場合である。
            find(v, V, d + 1, dist)
    
n = int(input()) # 頂点の数である。
# [isFind, d, f]
# A = [[False, 0, 0] for i in range(n)]
U = []
V = [] # U と V による隣接リスト表現を用いる。すなわち V はリストのリストである。
dist = [-1] * n # dist[i] は i までの距離である。到達不可能を -1 で表す。
for i in range(n):
    l = list(map(int, input().split())) # 入力 1 行を int のリストにする。
    U.append(l[0]) # U には出発点を格納する。
    V.append(l[2:]) # V には、それぞれの出発点からの目的地らを格納する。
find(1, V, 0, dist)

for u in U:
    print(u, dist[u - 1])
