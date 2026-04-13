/* Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list and return the head
struct Node* createList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to rotate
struct Node* rotateRight(struct Node* head, int n, int k) {
    if (!head || k == 0 || n == 0) return head;

   
    k = k % n;
    if (k == 0) return head;

    struct Node* tail = head;
   
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;


    int stepsToNewTail = n - k;
    struct Node* newTail = tail; 
    while (stepsToNewTail--) {
        newTail = newTail->next;
    }


    head = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* head = createList(n);
    
    if (scanf("%d", &k) != 1) return 0;

    head = rotateRight(head, n, k);
    printList(head);

    return 0;
}