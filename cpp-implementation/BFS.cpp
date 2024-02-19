#include <bits/stdc++.h>

using namespace std;
class BFS {
    unordered_map<int, vector<int>> adj;
public:
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void BFS(int start) {
        unordered_map<int, bool> visited;
        for (const auto& pair : adj) {
            visited[pair.first] = false;
        }
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();
            for (int i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

class BFS1 {
    int V;
    // vector<list<int>> adj;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();
            for (int i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

class BFS3 {
    int V;
    list<int> *adj;
public:
    Graph(int V) : V(V) {
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            cout << v << " ";
            q.pop();
            for (int i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    ~Graph() {
        delete[] adj;
    }
};

   
