#!/usr/bin/env python3
# -*- coding: utf-8 -*-
cost_a, cost_b, my_money = map(int, input().split())
cheaper = min(cost_a, cost_b)
num_manju = my_money // cheaper
print(num_manju)
