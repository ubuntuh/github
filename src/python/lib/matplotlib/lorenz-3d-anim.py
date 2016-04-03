#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# https://jakevdp.github.io/blog/2013/02/16/animating-the-lorentz-system-in-3d/
import numpy as np
from scipy import integrate
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import cnames
from matplotlib import animation
N_trajectories = 20 # 軌道の数。
def lorentz_deriv(xyz, t0, sigma=10, beta=8./3, rho=28.):
    x, y, z = xyz
    return [sigma * (y - x), x * (rho - z) - y, x * y - beta * z]
np.random.seed(1)
x0 = -15 + 30 * np.random.random((N_trajectories, 3)) # -15 から 15 までの乱数。N_trajectories*3 個の乱数を得る。[[-2.489, 6.609, -14.996], [-5.930, -10.597, -12.229], ...]
t = np.linspace(0, 4, 1000) # 0 から 4 までの間で 1000 個の要素を作る。[0, 0.004, 0.008, ..., 4]。
x_t = np.asarray([integrate.odeint(lorentz_deriv, x0i, t) for x0i in x0])
# odeint(func, y0, t, ...)
# func = callable(y, t0, ...) = computes the derivative of y at t0.
# y0 = array = initial condition on y
# t = array = a sequence of time points for which to solve for y. The initial value point should be the first element of this sequence.
fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1], projection="3d")
ax.axis("off")
colors = plt.cm.jet(np.linspace(0, 1, N_trajectories))
lines = sum([ax.plot([], [], [], "-", c=c) for c in colors], [])
pts = sum([ax.plot([], [], [], "o", c=c) for c in colors], [])
ax.set_xlim((-25, 25))
ax.set_ylim((-35, 35))
ax.set_zlim((5, 55))
ax.view_init(30, 0)
def init():
    for line, pt in zip(lines, pts):
        line.set_data([], [])
        line.set_3d_properties([])
        pt.set_data([], [])
        pt.set_3d_properties([])
    return lines + pts
def animate(i):
    i = (2 * i) % x_t.shape[1]
    for line, pt, xi in zip(lines, pts, x_t):
        x, y, z = xi[:i].T
        line.set_data(x, y)
        line.set_3d_properties(z)
        pt.set_data(x[-1:], y[-1:])
        pt.set_3d_properties(z[-1:])
    ax.view_init(30, 0.3 * i)
    fig.canvas.draw()
    return lines + pts
anim = animation.FuncAnimation(fig, animate, init_func=init, frames=500, interval=30, blit=True)
# FuncAnimation(fig, func, frames, init_func, ...)
# init_func = a function used to draw a clear frame.
# frames = number of frames.
# interval = draws a new frame every interval milliseconds.
plt.show()
