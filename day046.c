/* Problem: Level Order Traversal - Corrected implementation */

#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to construct the tree from level-order input array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    int i = 0;
    struct Node* root = createNode(arr[i++]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (i < n && front < rear) {
        struct Node* current = queue[front++];
        
        // Left child
        if (i < n) {
            current->left = createNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }
        // Right child
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}

// Function to perform Level Order Traversal
void levelOrderTraversal(struct Node* root, int n) {
    if (root == NULL) return;

    // Use an array-based queue
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    // Get number of elements
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    levelOrderTraversal(root, n);
    printf("\n");

    // Note: In a real scenario, you'd also write a function to free the tree memory
    free(arr);
    return 0;
}