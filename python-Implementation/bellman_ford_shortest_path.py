# Bellman-Ford is a single source shortest path algorithm that determines the shortest path between a given source vertex and every other vertex in a graph.
# It is slower than Dijkstra's algorithm for the same problem, but more versatile, as it is capable of handling negative edge weights.
# This algorithm can be used on both weighted and unweighted graphs.
# The shortest path cannot be found if there exists a negative cycle in the graph. 
# Bellman-Ford is also capable of detecting negative cycles.
# The time complexity of the algorithm is O(V*E) where V is the number of vertices and E is the number of edges in the graph.
# The space complexity of the algorithm is O(V) where V is the number of vertices in the graph.

"""
    Algorithm to Find Negative Cycle in a Directed Weighted Graph Using Bellman-Ford:
    Initialize distance array dist[] for each vertex ‘v‘ as dist[v] = INFINITY.
    Assume any vertex (let’s say ‘0’) as source and assign dist = 0.
    Relax all the edges(u,v,weight) N-1 times as per the below condition:
    dist[v] = minimum(dist[v], distance[u] + weight)
    Now, Relax all the edges one more time i.e. the Nth time and based on the below two cases we can detect the negative cycle:
    Case 1 (Negative cycle exists): For any edge(u, v, weight), if dist[u] + weight < dist[v]
    Case 2 (No Negative cycle) : case 1 fails for all the edges.
"""


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])
    
    def bellman_ford(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0
        # Relax all edges |V| - 1 times. A simple shortest path from src to any other vertex can have at-most |V| - 1 edges
        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in self.graph:
            if dist[u] != float("Inf") and dist[u] + w < dist[v]:
                print("Graph contains negative weight cycle")
                return
        return dist