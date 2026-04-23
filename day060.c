/* Check whether a given binary tree satisfies the Min-Heap property. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(struct Node* root, int index, int node_count) {
    if (root == NULL) return true;
    if (index >= node_count) return false;
    return isComplete(root->left, 2 * index + 1, node_count) &&
           isComplete(root->right, 2 * index + 2, node_count);
}

bool isMinHeapProperty(struct Node* root) {
    if (root->left == NULL && root->right == NULL) return true;

    if (root->right == NULL) {
        return root->data <= root->left->data;
    } else {
        if (root->data <= root->left->data && root->data <= root->right->data) {
            return isMinHeapProperty(root->left) && isMinHeapProperty(root->right);
        } else {
            return false;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    int total_nodes = countNodes(root);

    if (isComplete(root, 0, total_nodes) && isMinHeapProperty(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}