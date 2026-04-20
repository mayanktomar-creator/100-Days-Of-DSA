/* Problem: Find the Lowest Common Ancestor (LCA) in a BST */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Function to find LCA in a BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    // If both n1 and n2 are smaller than root, LCA is in left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both n1 and n2 are greater than root, LCA is in right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // We have found the split point (or root is one of the nodes)
    return root;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;

    // Input total nodes
    if (scanf("%d", &n) != 1) return 0;

    // Build the BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input the two nodes to find LCA for
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}