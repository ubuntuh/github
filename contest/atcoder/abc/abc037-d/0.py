#!/usr/bin/env python3
# -*- coding: utf-8 -*-
height, width = map(int, input().split())
grid = []
for _ in range(height):
    row = list(map(int, input().split()))
    grid.append(row)
indegreess = [[0] * width for _ in range(height)]
moves = ((0, -1), (0, 1), (-1, 0), (1, 0))
for i in range(height):
    for j in range(width):
        for move in moves:
            dx, dy = move
            jj = j + dx
            ii = i + dy
            if jj < 0 or width - 1 < jj:
                continue
            if ii < 0 or height - 1 < ii:
                continue
            src = grid[i][j]
            dst = grid[ii][jj]
            if dst < src:
                indegreess[ii][jj] += 1
zero_degrees = []
for i in range(height):
    for j in range(width):
        if indegreess[i][j] == 0:
            zero_degrees.append((j, i))
num_routes = [[1] * width for _ in range(height)]
while (zero_degrees):
    j, i = zero_degrees.pop()
    for move in moves:
        dx, dy = move
        jj = j + dx
        ii = i + dy
        if jj < 0 or width - 1 < jj:
            continue
        if ii < 0 or height - 1 < ii:
            continue
        src = grid[i][j]
        dst = grid[ii][jj]
        if dst < src:
            num_routes[ii][jj] += num_routes[i][j]
            indegreess[ii][jj] -= 1
            if indegreess[ii][jj] == 0:
                zero_degrees.append((jj, ii))
print(sum(map(sum, num_routes)))
