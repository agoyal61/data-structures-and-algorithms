#include <bits/stdc++.h>
using namespace std;

// Find cycle in a graph
// Time complexity: O(V+E)
// Space complexity: O(V)
// adj is the adjacency list of the graph and n is the number of vertices
// adj[i] contains all the vertices adjacent to vertex i
// works for both directed and undirected graphs
bool hasCycle(vector<vector<int>>& adj, int n) {
    vector<int> visited(n, 0); // 0: unvisited, 1: visited, 2: processed
    vector<int> parent(n, -1); // To store the parent of each vertex
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (findCycle(i, adj, visited, parent))
                return true;
        }
    }
    return false;
}

bool findCycle(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            parent[v] = u;
            if (findCycle(v, adj, visited, parent))
                return true;
        } else if (visited[v] == 1) {
            parent[v] = u;
            return true;
        }
    }
    visited[u] = 2;
    return false;
}

// Another way to find cycle in a graph
// Time complexity: O(V+E)
// Space complexity: O(V)
// works for undirected graphs only
bool findCycle(vector<vector<int>>& adj, vector<int>& visited, int u, int parent) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            if (findCycle(adj, visited, v, u))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}