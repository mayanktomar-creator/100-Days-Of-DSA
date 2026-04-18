/* Problem: Binary Search Tree - Insert Operation */

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

// Function to insert a value into the BST (Recursive)
struct Node* insert(struct Node* root, int val) {
    // If the tree/subtree is empty, return a new node
    if (root == NULL) {
        return createNode(val);
    }

    // Otherwise, recur down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Inorder traversal to verify the BST (should print in sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, value;
    struct Node* root = NULL;

    // Input: Number of elements to insert
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            root = insert(root, value);
        }
    }

    // Output: Inorder traversal results
    inorder(root);
    printf("\n");

    return 0;
}