/* Problem: Zigzag (Spiral) Level Order Traversal */

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

// Build tree from level-order input
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

void printZigZag(struct Node* root, int n) {
    if (!root) return;

    // Use two stacks for alternating levels
    struct Node** s1 = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node** s2 = (struct Node**)malloc(sizeof(struct Node*) * n);
    int top1 = -1, top2 = -1;

    s1[++top1] = root;
    int leftToRight = 1;

    while (top1 >= 0) {
        // Process all nodes in current stack
        while (top1 >= 0) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);

            if (leftToRight) {
                if (temp->left) s2[++top2] = temp->left;
                if (temp->right) s2[++top2] = temp->right;
            } else {
                if (temp->right) s2[++top2] = temp->right;
                if (temp->left) s2[++top2] = temp->left;
            }
        }

        // Swap stacks and flip direction
        struct Node** tempStack = s1;
        s1 = s2;
        s2 = tempStack;
        top1 = top2;
        top2 = -1;
        leftToRight = !leftToRight;
    }
    free(s1);
    free(s2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    printZigZag(root, n);
    printf("\n");

    free(arr);
    return 0;
}