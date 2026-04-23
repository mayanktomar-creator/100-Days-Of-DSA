/* Construct a binary tree from given inorder and postorder traversal arrays and print its preorder traversal. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = createNode(postorder[(*postIndex)--]);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorderTraversal(root);
    printf("\n");

    free(inorder);
    free(postorder);
    return 0;
}