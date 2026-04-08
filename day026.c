/*
Problem: Doubly Linked List Insertion and Traversal
Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of last node
    last->next = new_node;

    // Make last node as previous of new node
    new_node->prev = last;
}

// Function to traverse and print the list in forward order
void printListForward(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) printf(" ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter the node elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) break;
        insertEnd(&head, value);
    }

    printf("Forward traversal: ");
    printListForward(head);

    return 0;
}