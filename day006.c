/*
Problem:
Given a sorted array of n integers, remove duplicates in-place
and print only the unique elements in order.
*/

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Index for unique elements
    int j = 0;

    // Traverse array and keep unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
