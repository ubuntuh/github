#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
from IPython.display import display

graph0 = nx.Graph([(0, 1), (1, 2), (1, 3), (3, 4), (3, 5), (4, 5), (5, 6), (6, 7), (6, 8), (7, 9), (8, 9), (8, 10), (9, 10)])
nx.draw(graph0)
plt.show()
cycles0 = nx.cycle_basis(graph0)
display(cycles0)


graph1 = nx.DiGraph([(0, 1), (1, 2), (2, 0), (0, 3), (3, 4), (3, 5), (4, 5)])
nx.draw(graph1)
plt.show()
cycles1 = nx.simple_cycles(graph1)
display(list(cycles1))
