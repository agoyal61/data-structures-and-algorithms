// Description: Graph implementation in C++.
#include <bits/stdc++.h>

///////////////////////////////////
vector<vector<int>> graph;
vector<vector<pair<int,int>>> graph; // graph with edge weight // u, v, w   // adjacency list with weight
vector<int> visited;
vector<bool> visited;
vector<unordered_set<int>> graph(n);

unordered_map<int, int> graph;
unordered_set<string> visited;
unordered_map<string, unordered_map<string, double>> graph; // graph with edge weight

 unordered_map<string, vector<string>> graph; // Adjacency list
 unordered_map<char,unordered_set<char>> g;
 unordered_map<char,int> indegree;
 unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

unordered_map<int,vector<pair<int,int>>> graph;  // adjacency list with weight

vector<vector<pair<int,double>>> graph(n);

////////////// dfs graph implementation ////////////////

class Solution {
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


vector<vector<int>> graph(numCourses, vector<int>());  // graph
vector<int> visited(numCourses, 0);  // visited

///////////////////////// DFS and Graph Representation ///////////////////////
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i){
}

========================== BFS and Graph Representation ====================

// This class represents a directed graph using
// adjacency list representation
class Graph {

    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    vector<list<int> > adj;

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false); 
    // Create a queue for BFS
    list<int> queue  
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);   
    while (!queue.empty())  
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

//////////// Another function of BFS ///////////////////////

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> queue;

    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop();
        for (int i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

//////////////////// dfs //////////////////////
class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    vector<bool> visited;

    graph.clear();
    visited.assign(n, false);
}

for (auto [nextCity, roadToReverse] : graph[city]) {}
vector<vector<int>>& connections;
for (auto& connection : connections) {}