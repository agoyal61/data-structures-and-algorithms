#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

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
