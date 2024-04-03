#include <bits/stdc++.h>

using namespace std;

// Floyd Warshall Algorithm: All pairs shortest path algorithm for graphs with negative weights

/*
    Floyd-Warshall algorithm to find the shortest path between all pairs of nodes in a graph with negative weights.
    Steps:
    1. Initialize the distance matrix with the weights of the edges.
    2. For each pair of nodes (i, j), check if the distance from i to j is greater than the distance from i to k + distance from k to j, where k is an intermediate node.
    3. Update the distance matrix with the minimum of the two distances.
    4. Repeat the process for all pairs of nodes.
    
    Time complexity: O(V^3)
    Space complexity: O(V^2)
    
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

    // it is used to find the shortest path between all pairs of nodes in a graph with negative weights
    // it works with negative weight cycle
*/

// graph is the adjacency matrix of the graph and n is the number of nodes in the graph
// graph[i][j] = 0 if there is no edge between nodes i and j else graph[i][j] is the weight of the edge between nodes i and j
void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // To store the distance between all pairs of nodes

    // Initialize the distance matrix with the weights of the edges
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // For each pair of nodes (i, j), check if the distance from i to j is greater than the distance from i to k + distance from k to j, where k is an intermediate node
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Distance from " << i << " to " << j << " is " << dist[i][j] << endl;
        }
    }
}