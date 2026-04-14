/* Problem: Find the height (maximum depth) of a given binary tree. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to construct the tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        // Left Child
        if (i < n) {
            current->left = createNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }

        // Right Child
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}

// Function to calculate the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively find the height of each subtree
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Height is 1 + maximum of the heights of the subtrees
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    // Calculate and print height
    printf("%d\n", findHeight(root));

    free(arr);
    return 0;
}