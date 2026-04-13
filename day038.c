/* Problem: Deque (Double-Ended Queue) - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list to support Deque operations
struct Node {
    int data;
    struct Node *next, *prev;
};

struct Deque {
    struct Node *front, *rear;
    int count;
};

// Initialize Deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    dq->count = 0;
    return dq;
}

void push_front(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL)
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
    dq->count++;
}

void push_back(struct Deque* dq, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL)
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
    dq->count++;
}

void pop_front(struct Deque* dq) {
    if (dq->front == NULL) return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;
    free(temp);
    dq->count--;
}

void pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;
    free(temp);
    dq->count--;
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque* dq = createDeque();
    char op[20];
    int val, n;

    // Assuming N operations for the test case
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &val);
            push_front(dq, val);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &val);
            push_back(dq, val);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front(dq);
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back(dq);
        } else if (strcmp(op, "front") == 0) {
            if (dq->front) printf("%d\n", dq->front->data);
        } else if (strcmp(op, "back") == 0) {
            if (dq->rear) printf("%d\n", dq->rear->data);
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", dq->count);
        }
    }
    
    display(dq);

    return 0;
}