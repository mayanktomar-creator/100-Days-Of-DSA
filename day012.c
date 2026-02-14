/*
Problem:
Check whether a given matrix is symmetric.
A matrix is symmetric if it is square and
A[i][j] == A[j][i] for all i and j.
*/

#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is square
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Check symmetry condition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");

    return 0;
}
