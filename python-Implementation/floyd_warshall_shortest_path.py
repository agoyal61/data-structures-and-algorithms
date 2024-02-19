
# Floyd Warshall Algorithm for finding shortest path between all pairs of vertices
# It is used to find the shortest paths between all pairs of nodes in a weighted graph.
# The algorithm works for both directed and undirected graphs.
# This algorithm is highly efficient and can handle graphs with both positive and negative edge weights
# The time complexity of the algorithm is O(V^3) where V is the number of vertices in the graph.
# The space complexity of the algorithm is O(V^2) where V is the number of vertices in the graph.

def floydWarshall(graph):
    V = len(graph)
    # dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
    dist = [[float("inf") if i != j else 0 for j in range(V)] for i in range(V)]
    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist


""""
    Pseudo-Code of Floyd Warshall Algorithm :
    For k = 0 to n-1
    For i = 0 to n-1
    For j = 0 to n-1
    Distance[i, j] = min(Distance[i, j], Distance[i, k] + Distance[k, j])
    where i = source Node, j = Destination Node, k = Intermediate Node
    k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]
"""
