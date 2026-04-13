/* Problem: Convert an infix expression to postfix notation using stack. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

// Function to push element to stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop element from stack
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* exp) {
    int i, k;
    int len = strlen(exp);
    char result[MAX];
    k = 0;

    for (i = 0; i < len; i++) {
        // If character is an operand, add it to output
        if (isalnum(exp[i])) {
            result[k++] = exp[i];
        }
        // If character is '(', push to stack
        else if (exp[i] == '(') {
            push('(');
        }
        // If character is ')', pop and output until '(' is found
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                result[k++] = pop();
            }
            pop(); // Remove '('
        }
        // If an operator is scanned
        else {
            while (top != -1 && precedence(exp[i]) <= precedence(stack[top])) {
                result[k++] = pop();
            }
            push(exp[i]);
        }
    }

    // Pop all remaining operators from stack
    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp[MAX];
    if (scanf("%s", exp) != 1) return 0;
    
    infixToPostfix(exp);

    return 0;
}