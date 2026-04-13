/* Problem: Implement a Priority Queue using an array. An element with smaller value has higher priority. */

#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Function to insert an element into the priority queue
void insert(int x) {
    if (size >= MAX) return;
    
    // Insert at the end and maintain sorted order (Ascending)
    // Smaller value = Higher Priority, so we keep it at the end (or front)
    // For easy deletion of highest priority, let's keep smallest at the end.
    int i = size - 1;
    while (i >= 0 && pq[i] < x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;
}

// Function to delete the element with the highest priority (smallest value)
void delete() {
    if (size == 0) {
        printf("-1\n");
    } else {
        // Since we kept smallest at the end, we just decrement size
        printf("%d\n", pq[--size]);
    }
}

// Function to peek the element with the highest priority
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[size - 1]);
    }
}

int main() {
    int n, value;
    char op[10];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}