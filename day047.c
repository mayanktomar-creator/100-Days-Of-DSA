/* Problem: Calculate the Height of a Binary Tree */

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

// Function to construct the tree from level-order input
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

// Function to find the height of the tree
int findHeight(struct Node* node) {
    // Base Case: Empty tree has height 0
    if (node == NULL) {
        return 0;
    }

    // Recursive Case: 1 + max height of subtrees
    int leftH = findHeight(node->left);
    int rightH = findHeight(node->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    int n;
    // Input number of elements in level-order array
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    printf("%d\n", findHeight(root));

    free(arr);
    return 0;
}