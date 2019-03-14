#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

struct node *insert(struct node *root, int data) {
    if (root == NULL) return new node(data);
    else if (data <= root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data); 
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 10);
    insert(root, 70);
    insert(root, 90);
    inorder(root);
    return 0;
}