/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int n) {
    if (n <= 0) return NULL;

    struct Node *head = NULL, *tail = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself to maintain circularity
            tail = head;
        } else {
            tail->next = newNode; // Link previous node to new node
            newNode->next = head; // Link new node back to head
            tail = newNode;       // Update tail to the latest node
        }
    }
    return head;
}

// Function to traverse and print the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we complete the circle back to head
    printf("\n");
}

int main() {
    int n;
    
  
    if (scanf("%d", &n) != 1) return 0;

   
    struct Node* head = createCircularList(n);
    displayList(head);

    return 0;
}