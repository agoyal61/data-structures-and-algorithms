#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
    Kruskal's algorithm to find Minimum Spanning Tree (MST) of a given connected, undirected and weighted graph.
    Steps:
    1. Sort all the edges in non-decreasing order of their weight.
    2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
    3. Repeat step 2 until there are (V-1) edges in the spanning tree.

    Time complexity: O(ElogE) or O(ElogV)
    Space complexity: O(V)

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

// template 2
// edges[i] = {u, v, weight} where u and v are nodes and weight is the weight of the edge // n is the number of nodes
void kruskalMST(vector<vector<int>>& edges, int n) {
    // Sort edges based on their weights 
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    // Create a disjoint set
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    // Find the parent of a node
    function<int(int)> find = [&](int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    // Union of two sets
    auto Union = [&](int u, int v) {
        parent[find(u)] = find(v);
    };

    // Initialize the MST
    vector<vector<int>> mst;
    int cost = 0;

    // Iterate through all edges
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];

        // Check if the nodes are in the same set
        if (find(u) != find(v)) {
            mst.push_back({u, v, weight});
            cost += weight;
            Union(u, v);
        }
    }

    // Print the MST
    for (const auto& edge : mst) {
        cout << edge[0] << " - " << edge[1] << " : " << edge[2] << endl;
    }
}



// Edge structure to store edges and their weights
 // other way to Create a vector to store the edges of the graph
//  vector<vector<int>> edges; // weight, u, v or u, v, wt
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

// template 1
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

    KruskalMST(graph);

    return 0;
}


/*
 Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph.

Algorithm -
1. Sort Edges: First, sort all the edges of the graph in non-decreasing order of their weights.

2. Select Edges: Starting from the smallest edge, select edges one by one. Add each selected edge to the MST if it does not form a cycle with the edges already selected.

3 .Union-Find Data Structure: To efficiently determine whether adding an edge will form a cycle, Kruskal's algorithm typically employs a disjoint-set data structure (also known as union-find). This data structure maintains disjoint sets of elements, and efficient operations for checking connectivity and merging sets.

4. Repeat: Repeat step 2 until there are n−1 edges in the MST, where n is the number of vertices in the graph.

5. Output: The set of edges selected forms the minimum spanning tree.
*/

/*
 - Minium spanning tree, number of vertices = n, no of edges = n-1
 - intermediate stage may be disconnected in kruskal, however in prims it is always connected
 - Time complexity 
    - using min heap (V + E) log E

*/