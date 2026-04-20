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

// Function to find the min and max horizontal distance
void findMinMax(struct Node* node, int *min, int *max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Helper to print a specific column
void printVerticalLine(struct Node* node, int line_no, int hd) {
    if (node == NULL) return;
    if (hd == line_no) printf("%d ", node->data);
    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through each vertical line from min to max
    for (int line_no = min; line_no <= max; line_no++) {
        printVerticalLine(root, line_no, 0);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    printf("\n");

    free(arr);
    return 0;
}