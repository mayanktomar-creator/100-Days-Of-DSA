/* Build a graph using an adjacency matrix representation. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) == 2) {
            if (u >= 0 && u < n && v >= 0 && v < n) {
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}