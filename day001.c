/*
Day 1 - Question 1: Insert an Element in an Array

*/

#include <stdio.h>

int main() {
    int n, pos, x;

    // Read the size of the array
    scanf("%d", &n);

    // Declare array with extra space for insertion
    int arr[n + 1];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position (1-based index)
    scanf("%d", &pos);

    // Read element to be inserted
    scanf("%d", &x);

    // Shift elements to the right to create space
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the given position
    arr[pos - 1] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
