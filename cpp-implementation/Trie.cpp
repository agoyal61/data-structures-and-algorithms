#include <bits/stdc++.h>

using namespace std;

// Trie data structure
// Time complexity: O(n), Space complexity: O(n)
// it is a tree data structure used to store a dynamic set of strings
// it is used in information retrieval and searching
// it is used in autocomplete systems
// it is used in spell checkers
// it is used in IP routing (Longest Prefix Matching)
// it is used in prefix matching
// it is used in pattern matching
// it is used in finding the longest common prefix
// it is used in finding the longest common suffix
// it is used in finding the longest common substring
// it is used in finding the longest common subsequence
// it is used in finding the longest repeated substring
// it is used in finding the longest palindrome substring
// it is used in finding the longest palindrome subsequence
// it is used in finding the longest repeated subsequence
// it is used in finding the longest common prefix array
// it is used in finding the longest common suffix array
// it is used in finding the longest common substring array
// it is used in finding the longest common subsequence array
// it is used in finding the longest repeated substring array
// it is used in finding the longest palindrome substring array
// it is used in finding the longest palindrome subsequence array
// it is used in finding the longest repeated subsequence array
// it is used in finding the longest common prefix suffix array
// it is used in finding the longest common prefix substring array
// it is used in finding the longest common prefix subsequence array
// it is used in finding the longest common suffix substring array
// it is used in finding the longest common suffix subsequence array
// it is used in finding the longest common substring subsequence array

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


// implementation of trie
class Trie {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEndOfWord(false) {}
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};