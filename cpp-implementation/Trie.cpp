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

// Trie implementation

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
    bool searchInNode(string& word, int index, TrieNode *node){
        if(index == word.size()){
            return node->isEndOfWord;
        }
        char currentchar = word[index];
        if(currentchar != '.'){
            if(node->children.find(currentchar)==node->children.end()){
                return false;
            }else{
               return searchInNode(word,index+1,node->children[currentchar]); 
            }
        } else {
            for(auto &pair: node->children){
                if(searchInNode(word, index+1, pair.second)){
                    return true;
                }
            }
            return false;
        }
    }

    void addWord(string word) {
        TrieNode *node=root;
        for(char ch:word){
            if(node->children.find(ch)==node->children.end()){
                node->children[ch]= new TrieNode();
            }
            node=node->children[ch];
        }
        node->isEndOfWord=true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};

