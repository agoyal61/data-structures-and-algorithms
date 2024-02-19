#include <bits/stdc++.h>

using namespace std;
struct TrieNode {
    int count=0;
    unordered_map<int,TrieNode*> children;
};