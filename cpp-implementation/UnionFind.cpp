#include <bits/stdc++.h>

using namespace std;

// UnionFind for Integer
// Disjoint Set Union (DSU) or Union Find algorithm
// Time complexity: O(1) for find and union operations, Space complexity: O(n)
// it is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets
// it is used to find whether two elements are in the same set or not and to merge two sets
// it is used in Kruskal's algorithm to find the minimum spanning tree of a graph
// it is used in image processing to find connected components
// it is used in network connectivity algorithms
// it is used in LCA (Lowest Common Ancestor) algorithms
// it is used in dynamic connectivity problems
// it is used in finding the number of connected components in a graph
// it is used in finding the number of islands in a grid
// it is used in finding the number of connected components in a grid
// it is used in finding the number of connected components in a matrix
// it is used in finding the number of connected components in a tree
// it is used in finding the number of connected components in a graph with edges


// template 1
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        parent[find(x)] = find(y);
    }

};

// template 2
class UnionFind{
    public:
        vector<int> parent;
        UnionFind(int size) : parent(size){
            iota(parent.begin(),parent.end(),0); // iota assigns increasing values to the elements of the container starting from the given value
        }
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        bool unionSet(int x, int y){
            int rootx=find(x);
            int rooty=find(y);
            if(rootx==rooty) return false;
            parent[rooty]=rootx;
            return true;
        }
};

// Naive implementation of find
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Naive implementation of union()
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}


// rank or size optimization

int find(vector<int>& rep, int x){
    if(rep[x]!=x){
        rep[x]=find(rep,rep[x]);
    }
    return rep[x];
}
int performUnion(vector<int>& rep, vector<int>& size, int x, int y){
    int px=find(rep,x), py=find(rep,y);
    if(px==py)return 0;
    if(size[px]>size[py]){
        rep[py]=px;
        size[px]+=size[py];
    }else{
        rep[px]=py;
        size[py]+=size[px];
    }
    return  1;
}

// template 3
// UnionFind for String
class UnionFind{
    public:
        map<string,string> parent;
        map<string,int> rank;

        void addWord(string s){
            if(!parent.count(s)){
                parent[s]=s;
                rank[s]=0;
            }
        }
        bool isPresent(string s){
            return parent.count(s);
        }
        string find(string s){
            if(parent[s]!=s){
                parent[s]=find(parent[s]);
            }
            return parent[s];
        }
        void unionSet(string x, string y){
            string px=find(x), py=find(y);
            if(px==py)return;
            else if(rank[px]<rank[py]){
                parent[px]=py;
            } else if(rank[py]<rank[px]){
                parent[py]=px;
            }else {
                parent[py]=px;
                rank[px]++;
            }
        }
};

// template 4 with rank
// with rank
class UnionFind{
    private:
        vector<int> parent,rank;
    public:
        UnionFind(int size){
            parent.resize(size); 
            rank.resize(size,0);
            for(int i=0;i<size;i++)parent[i]=i;
        }    
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        void union_set(int x, int y){
            int px=find(x),py=find(y);
            if(px==py)return;
            else if(rank[px]<rank[py]){
                parent[px]=py;
            }else if(rank[px]>rank[py]){
                parent[py]=px;
            }else{
                parent[py]=px;
                rank[px]++;
            }
        }
};

// template 5 with rank and path compression
class UnionFind{
    private:
        vector<int> parent,rank;
        int count;
    public:
        UnionFind(int size){
            count=size;
            parent.resize(size);
            rank.resize(size,0);
            for(int i=0;i<size;i++)parent[i]=i;
        }    
        int find(int x){
            if(parent[x]!=x){
                parent[x]=find(parent[x]);
            }
            return parent[x];
        }
        void union_set(int x, int y){
            int px=find(x),py=find(y);
            if(px==py)return;
            else if(rank[px]<rank[py]){
                parent[px]=py;
            }else if(rank[px]>rank[py]){
                parent[py]=px;
            }else{
                parent[py]=px;
                rank[px]++;
            }
        }
};


// other implementation of union find

class UnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

public:
    int find(int x) {
        if (parent.find(x) == parent.end())
            return x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }

    void insert(int x) {
        if (parent.find(x) != parent.end()) return;
        parent[x] = x;
        size[x] = 1;
    }

    bool contains(int x) {
        return parent.find(x) != parent.end();
    }
};
