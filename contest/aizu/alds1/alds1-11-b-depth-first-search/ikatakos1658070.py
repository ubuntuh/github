#!/usr/bin/env python3
# -*- coding: utf-8 -*-
n = int(input()) # 1 行目を取って int 型に変換し変数 n に格納する。
g = [None] * n # 隣接リスト表現でグラフを表す。
visited = [0] * n # それぞれの頂点が訪問済みであるかどうかを表す。
root = set(range(n)) # dfs の開始点の候補である。
ts = [[0, 0] for _ in range(n)] # それぞれの頂点について、開始時刻と終了時刻の組である。
t = 0 # 時刻である。
 
while n: # 頂点の数だけ反復する。
    l = list(map(int, input().split())) # 入力行を空白で分割してそれぞれ int 型としリストに纏めて変数 l で表す。
    connected = [i - 1 for i in l[2:]] # zero-based index で宛先頂点の番号のリストを得る。
    g[l[0] - 1] = [i - 1 for i in l[2:]] # g[ノード番号] に宛先リストを格納する。
    root -= set(connected) # 接続された島は dfs で辿れるので根としなくてよい。
    n -= 1
 
 
def dfs(i):
    global g, t, ts, visited # global 宣言しなければグローバルスコープに代入できない。
    lts = ts[i]
    t += 1
    lts[0] = t # 破壊的代入により開始時刻を記録する。
    visited[i] = 1 # 訪問済みであることを記録する。
    for c in g[i]: # 頂点 i から接続する宛先 c らについて。
        if not visited[c]: # もし宛先が訪問済みでないならば。
            dfs(c)
    t += 1
    lts[1] = t
 
if root:
    for r in sorted(root):
        dfs(r)
else:
    dfs(0)
 
for i, v in enumerate(ts): # enumerate 関数を使うと index を得られる。
    print(i + 1, *v) # * を使うとリストを展開できる。
