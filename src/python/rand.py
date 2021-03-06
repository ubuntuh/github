#!/usr/bin/python
# -*- coding: utf-8 -*-
import random

print("Python uses the Mersenne Twister as the core generator.")
# random.seed(0)
print("# random.seed(0) # Initialize the random number generator.")
v = random.random()
print("random.random() = " + str(v) + " # [0.0, 1.0)")
v = random.uniform(-1, 1)
print("random.uniform(-1, 1) = " + str(v) + " # [-1.0, 1.0]")
v = random.randrange(2)
print("random.randrange(2) = " + str(v) + " # {0, 1}")
v = random.randrange(10, 13)
print("random.randrange(10, 13) = " + str(v) + " # {10, 11, 12}")
v = random.randrange(0, 20, 5)
print("random.randrange(0, 20, 5) = " + str(v) + " # {0, 5, 10, 15}")
v = random.randint(0, 10)
print("random.randint(0, 10) = " + str(v) + " # {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}")
v = [0, 1, 2, 3]; random.shuffle(v)
print("v = [0, 1, 2, 3]; random.shuffle(v); v = " + str(v))
v = random.choice([0, 1, 2, 3])
print("random.choice([0, 1, 2, 3]) = " + str(v))
v = random.sample([0, 1, 2, 3], 3)
print("random.sample([0, 1, 2, 3], 3) = " + str(v))
v = random.normalvariate(50, 10)
print("random.normalvariate(50, 10) = " + str(v))
