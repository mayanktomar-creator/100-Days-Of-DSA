/*
Problem: Delete First Occurrence of a Key
Implement a linked list using dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) printf(" ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) break;
        insertEnd(&head, value);
    }

    if (scanf("%d", &key) != 1) return 0;

    deleteNode(&head, key);
    printList(head);

    return 0;
}