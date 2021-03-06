#!/usr/bin/python

import networkx as nx
import matplotlib.pyplot as plt
from pylab import *
from networkx.algorithms import matching

ls=[
[0,0,0,1,1],
[1,0,0,0,0],
[1,0,1,0,0],
[0,1,1,0,0],
[1,0,0,0,0]
]
g = nx.Graph()
a=['a'+str(i) for i in range(len(ls))]
b=['b'+str(j) for j in range(len(ls[0]))]
g.add_nodes_from(a,bipartite=0)
g.add_nodes_from(b,bipartite=1)

for i in range(len(ls)):
    for j in range(len(ls[i])):
        if ls[i][j] != 0:
            g.add_edge(a[i], b[j])
pos_a={}
x=0.100
const=0.100
y=1.0
for i in range(len(a)):
    pos_a[a[i]]=[x,y-i*const]

xb=0.500
pos_b={}
for i in range(len(b)):
    pos_b[b[i]]=[xb,y-i*const]

nx.draw_networkx_nodes(g,pos_a,nodelist=a,node_color='r',node_size=300,alpha=0.8)
nx.draw_networkx_nodes(g,pos_b,nodelist=b,node_color='b',node_size=300,alpha=0.8)

# edges
pos={}
pos.update(pos_a)
pos.update(pos_b)
#nx.draw_networkx_edges(g,pos,edgelist=nx.edges(g),width=1,alpha=0.8,edge_color='g')
nx.draw_networkx_labels(g,pos,font_size=10,font_family='sans-serif')
m=matching.maximal_matching(g)
nx.draw_networkx_edges(g,pos,edgelist=m,width=1,alpha=0.8,edge_color='k')

plt.show()
