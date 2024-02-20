from collections import defaultdict

# Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.
# Topological Sorting for a graph is not possible if the graph is not a DAG.
# The first vertex in topological sorting is always a vertex with an in-degree of 0 (a vertex with no incoming edges).

class Graph:
    def __init__(self, vertices):
        # self.graph = defaultdict(list)
        self.graph = {}
        self.vertices = vertices
        for vtx in vertices:
            self.graph[vtx] = []
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    def totpological_sort_util(self, v, vis, st):
        vis.add(v)
        for nbr in self.graph[v]:
            if nbr not in vis:
                self.totopological_sort_util(nbr, vis, st)
        st.append(v)
    
    def totpological_sort(self):
        vis = set()
        st = []
        for vtx in self.vertices:
            if vtx not in vis:
                self.totopological_sort_util(vtx, vis, st)
        return st[::-1] # return list in reverse order