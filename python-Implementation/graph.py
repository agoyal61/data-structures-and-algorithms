from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph=defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)

# graph = [set() for i in range(len(edges)+1)]
# visited = [False for i in range(len(graph))]