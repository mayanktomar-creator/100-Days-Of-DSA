/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation. */

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert terms and keep them sorted by exponent (descending)
void insertTerm(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    
    // If list is empty or new exponent is greater than head
    if (*head == NULL || exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        
        // If exponent already exists, add coefficients
        if (temp->exp == exp) {
            temp->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to print the polynomial in standard form
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print variable and exponent
        if (temp->exp != 0) {
            if (temp->exp == 1) {
                printf("x");
            } else {
                printf("x^%d", temp->exp);
            }
        }

        temp = temp->next;

        // Print '+' sign if there is another term
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Node* poly = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    displayPolynomial(poly);

    return 0;
}