/*
Problem:
Write a program to perform addition of two matrices having the same dimensions.
The sum of two matrices is obtained by adding corresponding elements.
*/

#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], sum[m][n];

    // Read first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Add matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result matrix
    printf("Resultant matrix after addition:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
