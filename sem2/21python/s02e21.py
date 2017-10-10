#!/usr/bin/python3

# Kuhn's algorithm for finding the maximum matching
def kuhn(v):
    if (used[v]):
        return False
    used[v] = True
    for i in range(0,len(graph[v])):
        w = graph[v][i]
        if (mt[w] == -1 or kuhn(mt[w])):
            mt[w] = v #alternation in the current edge: redirect edge adjacent with w to vertex v
            return True
    return False

def printData():
    #print('maximal matching size {}'.format(mt_size))
    print('Maximal matching:')
    for i in range(0,k):
        if (mt[i] != -1):
            print('[{}]   [{}]'.format(mt[i]+1, i+1))


def solve():
    for v in range(0,n):
        if (seen[v]):
            continue
        used = [False for i in range(0,n)]
        kuhn(v)

#the code within the 'if' block will be executed only when the code runs directly
if __name__ == '__main__':
    """
    n - number of vertices in first part of graph
    k - number of vertices in second part of graph
    m - number of edges in graph

    used - array for swring information about seen 
    and not seened vertices, it's needed just w avoid entering one vertex twice

    seen - supporting array for precision kuhn, for don't start from first vertex
    mt - array for swrage of edges forming the maximum matching (this information 
    is only for the vertices of the second fraction)
    """
    n,k,m = map(int, input('Please enter three digit separated by space: ').split())
    graph = [[] for i in range(0,n)]
    seen = [False for i in range(0,n)]
    used = [False for i in range(0,n)]
    mt = [-1 for i in range(0,k)]

    for i in range(0,m):
        v,w = map(int, input('Please enter two vertex num separated by space: ').split())
        v -= 1
        w -= 1
        graph[v].append(w)

    for j in range(n):
        print(graph[j])
    print('')

    """ 
    before solve+kuhn cycle find random matching 
    because otherwise solve+kuhn doesn't find other variants, 
    sometimes it's works good:
    """
    for i in range(0,n):
        for j in range(0,len(graph[i])):
            if (mt[graph[i][j]] == -1):
                mt[graph[i][j]] = i
                seen[i] = True
                break

    solve()
    printData()
