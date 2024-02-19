import heapq
from typing import List

# Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, edges networks.
# edges = [u,v,weight]

def minCost(n: int, edges:  List[List[int]]):
    graph = {i: [] for i in range(1, n+1)}
    for edges in edges:
        graph[edges[0]].append((edges[1], edges[2]))
        graph[edges[1]].append((edges[0], edges[2]))

    def dijkstra(start):
        distances = {city: float('inf') for city in graph}
        distances[start] = 0
        queue = [(0, start)]

        while queue:
            current_distance, current_city = heapq.heappop(queue)
            if current_distance > distances[current_city]:
                continue

            for neighbor, weight in graph[current_city]:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(queue, (distance, neighbor))
        
        return distances