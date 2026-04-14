/* Problem: Construct a Binary Tree from the given level-order traversal. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to construct the tree using a queue for level-order processing
struct Node* constructTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* current = queue[front++];

        // Process left child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[rear++] = current->left;
        }

        // Process right child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

// Function for inorder traversal (Left, Root, Right)
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = constructTree(arr, n);
    printInorder(root);
    printf("\n");

    return 0;
}