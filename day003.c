/*
Problem: Linear Search with Comparison Count

Description:
Write a C program to perform linear search to find a key k in an array.
Also count and display the number of comparisons performed during the search.

*/

#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int foundIndex = -1;

    // Read size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key to search
    printf("Enter key to search: ");
    scanf("%d", &k);

    // Linear search
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    // Print result
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
