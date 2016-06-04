#!/usr/bin/env python3
# -*- coding: utf-8 -*-
L, X, Y, S, D = map(int, input().split())
# print(L, X, Y, S, D)
if D < S:
    S = L - S
    D = L - D
    X = -X
speeds = [X - Y, X + Y]
times = []
for speed in speeds:
    # print('speed =', speed)
    if speed == 0:
        continue
    if speed < 0:
        speed = -speed
        distance = L + S - D
    elif speed > 0:
        distance = D - S
    # print('distance =', distance)
    time = distance / speed
    # print('time =', time)
    times.append(time)
min_time = min(times)
print(min_time)
