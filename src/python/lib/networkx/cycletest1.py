#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import networkx as nx
import matplotlib.pyplot as plt
from IPython.display import display

class C:
    def __init__(self):
        self.graph0 = nx.Graph([(0, 1), (1, 2), (1, 3), (3, 4), (3, 5), (4, 5), (5, 6), (6, 7), (6, 8), (7, 9), (8, 9), (8, 10), (9, 10)])
        nx.draw_circular(self.graph0)
        plt.show()
        self.cycles0 = nx.cycle_basis(self.graph0)
        display(self.cycles0)

        self.graph1 = nx.DiGraph([(0, 1), (1, 2), (2, 0), (0, 3), (3, 4), (3, 5), (4, 5)])
        nx.draw_circular(self.graph1)
        plt.show()
        self.cycles1 = nx.simple_cycles(self.graph1)
        display(list(self.cycles1))

        self.graph2 = nx.Graph()
        self.graph2.add_edge(0, 1, weight=2)
        self.graph2.add_edge(0, 2, weight=3)
        self.graph2.add_edge(0, 3, weight=1)
        self.graph2.add_edge(1, 3, weight=4)
        self.graph2.add_edge(2, 3, weight=1)
        self.graph2.add_edge(2, 4, weight=1)
        self.graph2.add_edge(3, 4, weight=3)
        pos = nx.circular_layout(self.graph2)
        labels = nx.get_edge_attributes(self.graph2, 'weight')
        nx.draw(self.graph2, pos=pos)
        nx.draw_networkx_edge_labels(self.graph2, pos=pos, edge_labels=labels)
        plt.show()
        print('Minimum Spanning Tree (MST): ')
        nx.draw(self.graph2, pos=pos, style='dashed')
        mst = nx.minimum_spanning_tree(self.graph2)
        nx.draw(mst, pos=pos, width=3)
        nx.draw_networkx_edge_labels(self.graph2, pos=pos, edge_labels=labels)
        plt.show()
        print('Single Source Dijkstra Path: ')
        ssdp = nx.single_source_dijkstra_path(self.graph2, 0)
        display(ssdp)
        print('Single Source Dijkstra Path Length: ')
        ssdpl = nx.single_source_dijkstra_path_length(self.graph2, 0)
        display(ssdpl)

