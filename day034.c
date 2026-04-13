/* Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for the stack using linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int poppedVal = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedVal;
}

// Function to perform the arithmetic operation
int performOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int main() {
    struct Node* stack = NULL;
    char buffer[1000];
    
    // Read the entire postfix expression
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;

    // Tokenize the input string by spaces
    char* token = strtok(buffer, " \n");
    
    while (token != NULL) {
        // If token is a number (handling multi-digit and negative numbers)
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } 
        // If token is an operator
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result = performOperation(val1, val2, token[0]);
            push(&stack, result);
        }
        token = strtok(NULL, " \n");
    }

    // The final result remains at the top of the stack
    printf("%d\n", pop(&stack));

    return 0;
}