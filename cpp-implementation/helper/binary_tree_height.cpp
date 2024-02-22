#include <bits/stdc++.h>

using namespace std;

// Binary Tree Node
struct node {
    int data;
    struct node *left, *right;
};

class Node {    
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// time complexity: O(n^2)
// space complexity: O(n)
int diameter(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

