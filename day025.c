/*
Problem: Count Occurrences of an Element in Linked List
Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a key in the list
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Enter the node elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) break;
        insertEnd(&head, value);
    }

    printf("Enter the key to count: ");
    if (scanf("%d", &key) != 1) return 0;

    int result = countOccurrences(head, key);

    printf("Count of %d: %d\n", key, result);

    return 0;
}