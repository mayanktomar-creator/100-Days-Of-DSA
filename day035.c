/* Problem: Queue Using Array - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node *front, *rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to display the queue elements
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Queue* q = createQueue();

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Read and enqueue n elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(q, value);
        }
    }

    // Print the queue
    displayQueue(q);

    return 0;
}