#include <bits/stdc++.h>
using namespace std;

class DFS {
    int V;
    list<int> *adj;
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }
};

class DFS1 {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
};

class DFS2 {
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int v) {
        unordered_map<int, bool> visited;
        for (const auto& pair : adj) {
            visited[pair.first] = false;
        }
        DFSUtil(v, visited);
    }

    void DFSUtil(int v, unordered_map<int, bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
};

class Graph {
public:
    vector<vector<int>> graph;
    vector<bool> vis;
    void dfs(int s){
        vis[s]=true;
        for(int v:graph[s]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
};

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    vector<bool> visited;

        graph.clear();
        visited.assign(n, false);
};
