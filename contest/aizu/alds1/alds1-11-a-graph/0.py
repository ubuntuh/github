#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Accepted.
num_nodes = int(input())
dict = {}
for i in range(num_nodes):
    node_info = list(map(int, input().split()))
    src_node = node_info[0] - 1
    dst_nodes = [x - 1 for x in node_info[2:]]
    for dst_node in dst_nodes:
        dict[(src_node, dst_node)] = 1
for i in range(num_nodes):
    for j in range(num_nodes):
        if (i, j) in dict:
            print(dict[(i, j)], end="")
        else:
            print(0, end="")
        if j != num_nodes - 1:
            print(" ", end="")
        else:
            print()
