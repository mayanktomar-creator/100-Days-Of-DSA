#include <stdio.h>

int main() {
    int n, k;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;   // handle k > n

    int temp[n];

    // Copy last k elements to front
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // Print result
    printf("Rotated array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}