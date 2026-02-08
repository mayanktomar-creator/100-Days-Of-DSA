/*
Q5 Problem:
A system receives two sorted logs of user arrival times from two servers.
Merge them into a single chronological log.
*/

#include <stdio.h>

int main() {
    int p, q;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    int log1[p];
    printf("Enter sorted arrival times of server 1:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    int log2[q];
    printf("Enter sorted arrival times of server 2:\n");
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;

    printf("Merged log:\n");

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    return 0;
}
