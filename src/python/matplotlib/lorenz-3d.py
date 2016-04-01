#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
def lorenz(x, y, z, s=10, r=28, b=2.667):
    x_dot = s*(y - x)
    y_dot = r*x - y - x*z
    z_dot = x*y - b*z
    return x_dot, y_dot, z_dot
dt = 0.01
step_count = 10000
xs = np.empty((step_count + 1,)) # 1*10001 行列を初期化せずに確保する。添字は 0 から 10000 になる。
ys = np.empty((step_count + 1,))
zs = np.empty((step_count + 1,))
xs[0], ys[0], zs[0] = (0., 1., 1.05)
for i in range(step_count): # 0 <= i <= 9999
    x_dot, y_dot, z_dot = lorenz(xs[i], ys[i], zs[i])
    xs[i + 1] = xs[i] + (x_dot * dt) # i 番目要素を用いて i + 1 番目要素を定める。
    ys[i + 1] = ys[i] + (y_dot * dt)
    zs[i + 1] = zs[i] + (z_dot * dt)
fig = plt.figure()
ax = fig.gca(projection="3d") # get the current Axes instance.
ax.plot(xs, ys, zs) # plot lines and/or markers to the Axes.
ax.set_xlabel("X Axis")
ax.set_ylabel("Y Axis")
ax.set_zlabel("Z Axis")
ax.set_title("Lorenz Attractor")
plt.show()
