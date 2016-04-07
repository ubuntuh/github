#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
from IPython.display import display

class C:
    def __init__(self):
        self.graph0 = nx.Graph([(0, 1), (1, 2), (1, 3), (3, 4), (3, 5), (4, 5), (5, 6), (6, 7), (6, 8), (7, 9), (8, 9), (8, 10), (9, 10)])
        nx.draw(self.graph0)
        plt.show()
        self.cycles0 = nx.cycle_basis(self.graph0)
        display(self.cycles0)

        self.graph1 = nx.DiGraph([(0, 1), (1, 2), (2, 0), (0, 3), (3, 4), (3, 5), (4, 5)])
        nx.draw(self.graph1)
        plt.show()
        self.cycles1 = nx.simple_cycles(self.graph1)
        display(list(self.cycles1))
