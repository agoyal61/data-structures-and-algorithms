#include <bits/stdc++.h>
using namespace std;

// color graph using backtracking
// Time complexity: O(V^V) where V is the number of vertices
// Space complexity: O(V)
// graph is the adjacency list of the graph and n is the number of vertices
// m is the number of colors
bool colorGraph(vector<vector<int>>& graph, int n, int m) {
    vector<int> color(n, -1); // To store the color of each vertex
    return colorGraphUtil(graph, n, m, color, 0);
}

// Check if it is safe to color the vertex with color c
// v is the vertex to be colored
bool colorGraphUtil(vector<vector<int>>& graph, int n, int m, vector<int>& color, int v) {
    if (v == n) {
        return true;
    }

    for (int c = 0; c < m; c++) {
        if (isSafe(graph, n, color, v, c)) {
            color[v] = c;
            if (colorGraphUtil(graph, n, m, color, v + 1))
                return true;
            color[v] = -1;
        }
    }
    return false;
}

// Check if it is safe to color the vertex v with color c
bool isSafe(vector<vector<int>>& graph, int n, vector<int>& color, int v, int c) {
    for (int u : graph[v]) {
        if (color[u] == c)
            return false;
    }
    return true;
}