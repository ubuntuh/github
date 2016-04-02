# http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1661007
class Node(object):
    def __init__(self, V):
        self.V = V
        self.d = -1 
   
n = int(input())
nodes = [0] * 101
for i in range(n):
    data = input().split()
    V = list(map(int, data[2:]))
    V.sort(reverse = True)
    nodes[int(data[0])] = Node(V)
   
l = [1,]
l_old = []
cnt = 0
 
while len(l) > 0:
    l_old = l
    l = []
    for i in l_old:
        if nodes[i].d == -1:
            nodes[i].d = cnt
            V = nodes[i].V
            for j in V:
                if not j in l:
                    if nodes[j].d == -1:
                        l.append(j)
    cnt += 1
for i in range(1, n+1):
    if not isinstance(nodes[i], int):
        print(i, nodes[i].d)
