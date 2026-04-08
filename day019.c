#include <stdio.h>
#include <stdlib.h>

// comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = 1000000000;
    int a = 0, b = 0;

    // Step 2: two pointer
    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            a = arr[left];
            b = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", a, b);

    return 0;
}