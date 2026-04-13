/* Problem: Implement push and pop operations on a stack and verify stack operations. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Function to display the stack from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    // Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Push n elements onto the stack
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Read number of pop operations
    if (scanf("%d", &m) != 1) return 0;

    // Perform m pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining elements
    display();

    return 0;
}