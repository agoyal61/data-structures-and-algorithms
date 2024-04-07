#include <bits/stdc++.h>

using namespace std;

// templeate 1 using BFS
// graph is the adjacency matrix of the graph and n is the number of vertices
void connectedComponents(vector<vector<int>>& graph, int n) {
    vector<int> parent(n, -1); // To store the connected components
    vector<bool> visited(n, false); // To keep track of visited vertices
    int component = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                parent[u] = component;

                for (int v = 0; v < n; v++) {
                    if (graph[u][v] && !visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " belongs to component " << parent[i] << endl;
    }
}

// templeate 2 using BFS
// edges is the list of edges of the graph and n is the number of vertices
void connectedComponents(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n); // Adjacency list of the graph
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // BFS to find connected components of the graph
    queue<int> q;
    vector<int> group(n, -1); // Group array to store component group of each vertex
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) {
            group[i] = i; // Assign component group ID
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (group[v] == -1) {
                        group[v] = i;
                        q.push(v);
                    }
                }
            }
        }
    }
}

// template 3 using DFS
// graph is the adjacency matrix of the graph and n is the number of vertices
void connectedComponents(vector<vector<int>>& graph, int n) {
    vector<int> parent(n, -1); // To store the connected components
    vector<bool> visited(n, false); // To keep track of visited vertices
    int component = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component++;
            dfs(graph, i, parent, visited, component);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " belongs to component " << parent[i] << endl;
    }
}

void dfs(vector<vector<int>>& graph, int u, vector<int>& parent, vector<bool>& visited, int component) {
    visited[u] = true;
    parent[u] = component;

    for (int v = 0; v < graph[u].size(); v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(graph, v, parent, visited, component);
        }
    }
}

// templeate 4 using DFS
// edges is the list of edges of the graph and n is the number of vertices
void connectedComponents(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n); // Adjacency list of the graph
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // DFS to find connected components of the graph
   unordered_map<int,int> mp;
   int component=1;
   vector<int> vis(n,0);
   for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,component,mp);
            component++;
        }
    }
}

void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis,int component,unordered_map<int,int> &mp){
    vis[node]=1;
    mp[node]=component;
    for (auto nbr :adj[node]){
        if(nbr == parent || vis[nbr]){
            continue;
        }
        dfs(nbr,node,adj,vis,component,mp);
    }
}

// template 5 using UnionFind
// edges is the list of edges of the graph and n is the number of vertices
void connectedComponents(vector<vector<int>>& edges, int n) {
    vector<int> parent(n, -1); // To store the connected components
    vector<int> rank(n, 0); // To keep track of the rank of each vertex
    int component = n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        if (unionSet(u, v, parent, rank)) {
            component--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " belongs to component " << find(i, parent) << endl;
    }
}

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

bool unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);

    if (rootX == rootY) return false;

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    return true;
}
