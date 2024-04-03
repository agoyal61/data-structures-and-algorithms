/*
Prims Algorithm: It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
1.Start with an arbitrary point and mark it as visited.
2.Find the shortest edge connecting the visited nodes to the unvisited nodes.
3.Mark the other endpoint of this edge as visited.
4.Add the edge's weight to the total cost.
5.Repeat steps 2-4 until all node are visited.

Time Complexity: O(V^2)
Space Complexity: O(V)

Applications:
1. Network design
2. Cluster analysis
3. Image segmentation
4. Shortest path in a maze
5. Approximation algorithms
6. Travelling Salesman Problem
7. Minimum Spanning Tree
8. Clustering
9. Image segmentation
10. Computer networks
11. Civil network design
12. Robotics
13. Computer vision
14. Machine learning    
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    // template 1
    int minCostConnectPoints(vector<vector<int>>& points, int n) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[0] = 0;
        int cost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }
            visited[u] = true;
            cost += dist[u];
            
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    dist[v] = min(dist[v], abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]));
                }
            }
        }
        return cost;
    }
};

// template 2
// graph is the adjacency matrix of the graph and n is the number of vertices // graph[i][j] = weight of edge between vertex i and vertex j
void primMST(vector<vector<int>>& graph, int n) {
    vector<int> parent(n, -1); // To store the MST
    vector<int> dist(n, INT_MAX); // Distance of each vertex from the MST
    vector<bool> visited(n, false); // To keep track of visited vertices
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1; // Find the vertex with the minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        visited[u] = true; // Mark the vertex as visited

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}