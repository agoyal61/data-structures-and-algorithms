#include <bits/stdc++.h>

using namespace std;

// Bellman Ford Algorithm: Single source shortest path algorithm for graphs with negative weights
/* 
    Bellman-Ford algorithm to find the shortest path from a source node to all other nodes in a graph with negative weights.
    Steps:
    1. Initialize the distance of the source node to 0 and all other nodes to infinity.
    2. Relax all edges V-1 times where V is the number of vertices in the graph.
    3. If there is a negative weight cycle, then the shortest path is not defined.
    4. If there is no negative weight cycle, then the shortest path is defined.
    
    Time complexity: O(VE)
    Space complexity: O(V)
    
    Applications:
    1. Shortest path in a maze
    2. Approximation algorithms
    3. Travelling Salesman Problem
    4. Minimum Spanning Tree
    5. Clustering
    6. Image segmentation
    7. Computer networks
    8. Civil network design
    9. Robotics
    10. Computer vision
    11. Machine learning

    // it does not work with negative weight cycle
    // it is used to find the shortest path from a source node to all other nodes in a graph with negative weights

*/

// edges[i] = {u, v, weight}, where u and v are the nodes and weight is the weight of the edge between u and v // n is the number of nodes in the graph and src is the source node
void bellmanFord(vector<vector<int>>& edges, int n, int src) {
    vector<int> dist(n, INT_MAX); // To store the distance of each node from the source node
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from source to " << i << " is " << dist[i] << endl;
    }
}