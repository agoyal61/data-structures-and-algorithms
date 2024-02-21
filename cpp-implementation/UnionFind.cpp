#include <bits/stdc++.h>

using namespace std;
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
            iota(parent.begin(),parent.end(),0);
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

//
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
