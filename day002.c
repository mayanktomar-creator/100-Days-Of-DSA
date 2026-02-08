/*
Problem: Delete an Element from an Array

Description:
Write a C program to delete the element at a given 1-based position pos
from an array of n integers. After deletion, shift the remaining elements
to the left.
*/

#include <stdio.h>

int main() {
    int n, pos;

    // Read size of the array
    printf("Enter size : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements : ");

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position to delete (1-based index)
    printf("Enter position to delete : ");
    scanf("%d", &pos);

    // Shift elements to the left from the given position
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n")

    return 0;
}
