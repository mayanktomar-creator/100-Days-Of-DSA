/* Problem: Count the number of leaf nodes in a Binary Tree */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    int i = 0;
    struct Node* root = createNode(arr[i++]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (i < n && front < rear) {
        struct Node* current = queue[front++];
        
        if (i < n) {
            current->left = createNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }
        if (i < n) {
            current->right = createNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    // Condition for leaf node
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    // Sum leaves from both subtrees
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    printf("%d\n", countLeafNodes(root));

    free(arr);
    return 0;
}