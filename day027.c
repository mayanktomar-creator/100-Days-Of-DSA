/*
Problem: Find Intersection Point of Two Linked Lists
Implement using linked list with dynamic memory allocation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Logic: Traverse both lists. When one reaches the end, redirect it to the head 
// of the other list. They will eventually meet at the intersection point.
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL) return NULL;

    struct Node* a = head1;
    struct Node* b = head2;

    while (a != b) {
        // If they don't intersect, both will eventually hit NULL at the same time
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    return a;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    // List 1 Input
    printf("Enter the number of nodes for List 1: ");
    scanf("%d", &n);
    printf("Enter elements for List 1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (head1 == NULL) head1 = temp;
        else tail1->next = temp;
        tail1 = temp;
    }

    // List 2 Input
    printf("Enter the number of nodes for List 2: ");
    scanf("%d", &m);
    printf("Enter elements for List 2: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (head2 == NULL) head2 = temp;
        else tail2->next = temp;
        tail2 = temp;
    }

    /* Note: In a real memory-linked scenario, intersection occurs when two 
       nodes share the same memory address. For the sake of this logic-based 
       problem, we find the first node where values match and remaining 
       sequences match.
    */
    
    struct Node* current1 = head1;
    struct Node* intersection = NULL;

    // Simulating finding the intersection by value for the provided example
    while (current1 != NULL) {
        struct Node* current2 = head2;
        while (current2 != NULL) {
            if (current1->data == current2->data) {
                // Check if the rest of the list matches to confirm intersection
                struct Node *t1 = current1, *t2 = current2;
                int match = 1;
                while (t1 && t2) {
                    if (t1->data != t2->data) { match = 0; break; }
                    t1 = t1->next; t2 = t2->next;
                }
                if (match) {
                    intersection = current1;
                    goto found;
                }
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

found:
    if (intersection) {
        printf("Intersection node value: %d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}