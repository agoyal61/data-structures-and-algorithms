#include <bits/stdc++.h>

using namespace std;
struct TrieNode {
    int count=0;
    unordered_map<int,TrieNode*> children;
};

// Node definition of a trie
struct Node {
    bool isWord = false;
    vector<Node *> children{vector<Node *>(26, NULL)};
} * Root, *curr;

class TrieNode {
    public:
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEndOfWord(false) {};
};

class WordDictionary {
private:
    TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode *node=root;
    }
    bool search(string word) {
    }
}

struct TrieNode {
    TrieNode* children[26];
    string word;
    TrieNode(){
        for(auto& child:children){
            child=nullptr;
            word="";
        } 
    }
};