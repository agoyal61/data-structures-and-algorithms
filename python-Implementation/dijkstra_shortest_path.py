import heapq
from typing import List

# Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, edges networks.
# edges = [u,v,wt]
# Time complexity: O(ElogV)
# single source shortest path algorithm
# single source least cost
# both directed and undirected graph
# all edge must have non-negative weight, it is not valid for negtaive weight
# graph must be connected 
# remove all self loop and parallel edge
# it is applied on weighted graph

def minCost(n: int, edges:  List[List[int]]):
    graph = {i: [] for i in range(1, n+1)}
    for edges in edges:
        graph[edges[0]].append((edges[1], edges[2]))
        graph[edges[1]].append((edges[0], edges[2]))

    def dijkstra(start):
        dist = {city: float('inf') for city in graph}
        dist[start] = 0
        q = [(0, start)]

        while q:
            curr_dist, curr_city = heapq.heappop(q)
            if curr_dist > dist[curr_city]:
                continue

            for nbr, wt in graph[curr_city]:
                d = curr_dist + wt
                if d < dist[nbr]:
                    dist[nbr] = d
                    heapq.heappush(q, (d, nbr))
        
        return dist