#include <bits/stdc++.h>

using namespace std;

// Binary Tree Node
/*
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
*/

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data);

int diameteropt(struct node *root, int *height) {
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    ldiameter = diameteropt(root->left, &lh);
    rdiameter = diameteropt(root->right, &rh);
    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int height = 0;
    cout << "Diameter of the given binary tree is " << diameteropt(root, &height) << endl;
    return 0;
}


