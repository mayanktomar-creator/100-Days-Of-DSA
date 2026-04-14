/* Problem: Given a queue of integers, reverse the queue using a stack. */

#include <stdio.h>
#include <stdlib.h>

// Structure for a Node (used by both Stack and Queue)
struct Node {
    int data;
    struct Node* next;
};

// Queue Structure
struct Queue {
    struct Node *front, *rear;
};

// Stack functions
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return -1;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Queue functions
void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

int main() {
    int n, val;
    struct Queue q = {NULL, NULL};
    struct Node* stack = NULL;

    if (scanf("%d", &n) != 1) return 0;

    // 1. Fill the queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // 2. Dequeue all elements from queue and push them to stack
    while (q.front != NULL) {
        push(&stack, dequeue(&q));
    }

    // 3. Pop all elements from stack and enqueue them back to queue
    while (stack != NULL) {
        enqueue(&q, pop(&stack));
    }

    // 4. Print the reversed queue
    struct Node* temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}