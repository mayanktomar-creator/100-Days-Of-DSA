/* Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularQueue {
    struct Node *front, *rear;
};

// Function to initialize the queue
struct CircularQueue* createQueue() {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element
void enqueue(struct CircularQueue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (q->front == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    q->rear->next = q->front; // Maintain circularity
}

// Function to remove an element
void dequeue(struct CircularQueue* q) {
    if (q->front == NULL) return;

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // Update circular link
        free(temp);
    }
}

// Function to display the queue
void display(struct CircularQueue* q) {
    if (q->front == NULL) return;

    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    struct CircularQueue* q = createQueue();
    int n, m, val;

    // Input number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(q, val);
    }

    // Input number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}