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


// Prims implementation with the heap using pq

struct Edge {
    int to;
    int weight;
};

struct Vertex {
    int id;
    int key;
    
    bool operator>(const Vertex& other) const {
        return key > other.key;
    }
};

vector<Edge> primMST(const vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    key[start] = 0;
    pq.push({start, 0});
    vector<Edge> MST;
    while (!pq.empty()) {
        int u = pq.top().id;
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        if (parent[u] != -1)
            MST.push_back({u, key[u]});
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({v, key[v]});
            }
        }
    }
    return MST;
}


/*
Prim's algorithm is another greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. The algorithm operates by building the tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from any vertex in the tree to a vertex that is not in the tree.

until it spans all vertices. Here's how Prim's algorithm works:

1. Initialization: Choose an arbitrary vertex to start the MST. Initialize an empty set (or heap) of vertices and an empty set of edges.

2. Grow the Tree: Repeat the following steps until all vertices are included in the MST:

Select the vertex v that is not yet in the MST and has the minimum edge weight connecting it to the MST. Add v to the MST.Add the edge connecting v to the MST to the set of edges.
3. Termination: When all vertices are included in the MST, the algorithm terminates.

4. Output: The set of edges collected during the execution of Prim's algorithm forms the minimum spanning tree.

Prim's algorithm can be implemented using various data structures for efficient selection and manipulation of vertices and edges. One common approach is to use a priority queue (usually implemented with a heap) to efficiently select the next vertex to add to the MST based on the weight of its connecting edge.
*/
