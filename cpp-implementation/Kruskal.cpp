#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Edge structure to store edges and their weights
struct Edge {
    int src, dest, weight;
};

// Graph structure
struct Graph {
    int V, E;
    vector<Edge> edges;

    // Constructor for graph
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Function to add an edge
    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
    }
};

// Disjoint Set structure for Union-Find
struct DisjointSets {
    vector<int> parent, rank;

    // Constructor
    DisjointSets(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the parent of a node
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    // Union of two sets
    void Union(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

// Function to compare two edges according to their weights
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find MST
void KruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result;
    int e = 0;

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Allocate memory for creating V sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    for (auto it = graph.edges.begin(); e < V - 1 && it != graph.edges.end(); ++it) {
        int u = it->src;
        int v = it->dest;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating a cycle or not
        if (set_u != set_v) {
            result.push_back(*it);
            ds.Union(set_u, set_v);
            e++;
        }
    }

    // Print the contents of result[] to display the MST
    for (auto it = result.begin(); it != result.end(); ++it)
        cout << it->src << " - " << it->dest << " : " << it->weight << endl;
}

int main() {
    // Create a graph given in the above diagram
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    Graph graph(V, E);

    // Adding edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Function call
    KruskalMST(graph);

    return 0;
}
