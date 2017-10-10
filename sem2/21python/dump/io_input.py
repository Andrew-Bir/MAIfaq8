#!/usr/bin/python
from __future__ import print_function
from six.moves import input

"""n = int(input("Enter the number of vertices in set U: "))
m = int(input("Enter the number of vertices in set V: "))
if (n < m):
    d = n
    n = m
    m = d

a = [[0] * m for i in range(n)]
j=0
for i in range(n):
    print( end=' ')
    if (j< m):
        print(' [{}]\t[{}]'.format(i, j))
        j = j + 1
    else:
        print(' [{}]'.format(i))

for i in range(n):
    k = int(input('Enter the number of edges in vertex from set U: '))
    for j in range(k):
        b = int(input('Enter the adjacent vertex from set V: '))
        a[i][b] = 1

print('adjacency matrix: ')
for i in range(n):
    for j in range(m):
        if (j < m - 1):
            print(' {}'.format(a[i][j]), end='  ')
        else:
            print(' {}'.format(a[i][j]))"""


# a,b= input("Please enter two digits separated by space").split()

class Vertex:
    def __init__(self, node):
        self.id = node
        self.adjacent = {}

    def __str__(self):
        return str(self.id) + ' adjacent: ' + str([x.id for x in self.adjacent])

    def get_connections(self):
        return self.adjacent.keys()  

    def get_id(self):
        return self.id

class Graph:
    def __init__(self):
        self.vert_dict = {}
        self.num_vertices = 0

    def __iter__(self):
        return iter(self.vert_dict.values())

    def add_vertex(self, node):
        self.num_vertices = self.num_vertices + 1
        new_vertex = Vertex(node)
        self.vert_dict[node] = new_vertex
        return new_vertex

    def get_vertex(self, n):
        if n in self.vert_dict:
            return self.vert_dict[n]
        else:
            return None

    def add_edge(self, frm, to, cost = 0):
        if frm not in self.vert_dict:
            self.add_vertex(frm)
        if to not in self.vert_dict:
            self.add_vertex(to)

    def get_vertices(self):
        return self.vert_dict.keys()

if __name__ == '__main__':

    n1 = int(input("Enter the number of vertices in set N1: "))
    n2 = int(input("Enter the number of vertices in set N2: "))
    m = int(input("Enter the number of edges: "))

    g = Graph()

    for i in range(n1):
        g.add_vertex('N1_%s'%i)
        
    for j in range(n2):
        g.add_vertex('N2_%s'%j)


    for k in range(m):
        a,b = input("Please enter two vertex_ID separated by space: ").split()
        g.add_edge(a,b)

    for v in g:
        for w in v.get_connections():
            vid = v.get_id()
            wid = w.get_id()
            print('( {} , {})',format(vid, wid))

    for v in g:
        print('g.vert_dict[{}]={}',format(v.get_id(), g.vert_dict[v.get_id()]))


