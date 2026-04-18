/* Problem: Binary Search Tree - Search Operation */

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST (to build the tree)
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Function to search for a value in the BST
// Returns the node if found, otherwise NULL
struct Node* search(struct Node* root, int target) {
    // Base Case: root is null or key is present at root
    if (root == NULL || root->data == target)
        return root;

    // Target is greater than root's data
    if (root->data < target)
        return search(root->right, target);

    // Target is smaller than root's data
    return search(root->left, target);
}

int main() {
    int n, val, target;
    struct Node* root = NULL;

    // Build the BST
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input the target to search for
    scanf("%d", &target);

    // Search and output
    if (search(root, target) != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}