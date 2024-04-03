#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Single source shortest path algorithm
// Time complexity: O((V+E)logV), Space complexity: O(V)
// it is a greedy algorithm, it finds the shortest path from a source vertex to all other vertices in the graph
// it works for both directed and undirected graphs
// it works for graphs with negative weights, but not for graphs with negative cycles
// it is not optimal for dense graphs, for dense graphs use Bellman-Ford algorithm
// it is optimal for sparse graphs
// it is optimal for graphs with positive weights and graphs with negative weights

/*
    Algorithm steps:  
    1. Initialize the distance of all vertices as infinity except the source vertex as 0 
    2. Create a priority queue to hold vertices and their distances
    3. Insert the source vertex with distance 0 into the priority queue
    4. While the priority queue is not empty, do the following:
        a. Extract the vertex with the minimum distance from the priority queue
        b. For each neighbor of the extracted vertex, do the following:
            i. If the distance of the neighbor is greater than the distance of the extracted vertex plus the weight of the edge between them, update the distance of the neighbor to the distance of the extracted vertex plus the weight of the edge between them
            ii. Insert the neighbor with the updated distance into the priority queue
    5. Print the distance of all vertices
*/ 
// it is used in finding the shortest path from a source vertex to all other vertices in a graph
// it is used in finding the shortest path from a source vertex to all other vertices in a weighted graph


void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap distance, vertex

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (d > dist[curr]) continue;
        for (auto& edge : graph[curr]) {
            int nbr = edge.first;
            int wt = edge.second;
            if (dist[nbr] > dist[curr] + wt) {
                dist[nbr] = dist[curr] + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }
}

int main() {
    // unordered_map<int,vector<pair<int,int>>> graph;  // adjacency list
    vector<vector<pair<int, int>>> graph(4);
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 3});
    dijkstra(graph, 0); 
    return 0;
}
