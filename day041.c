/* Problem: Implement a Queue using a linked list supporting enqueue and dequeue operations. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure to keep track of front and rear
struct Queue {
    struct Node *front, *rear;
};

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element (Enqueue)
void enqueue(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to remove an element (Dequeue)
void dequeue(struct Queue* q) {
    // If queue is empty, return -1
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    // Store previous front and move front one node ahead
    struct Node* temp = q->front;
    printf("%d\n", temp->data);
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    struct Queue* q = createQueue();
    int n, value;
    char op[20];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(q, value);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue(q);
        }
    }

    return 0;
}