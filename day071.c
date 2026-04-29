/* Implement a hash table using quadratic probing with formula: h(k, i) = (h(k) + i*i) % m */

#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;
        if (ht->table[index] == EMPTY || ht->table[index] == DELETED) {
            ht->table[index] = key;
            return;
        }
    }
}

int search(HashTable* ht, int key) {
    int m = ht->size;
    for (int i = 0; i < m; i++) {
        int index = (key % m + i * i) % m;
        if (ht->table[index] == EMPTY) {
            return -1;
        }
        if (ht->table[index] == key) {
            return index;
        }
    }
    return -1;
}

int main() {
    int m, n, key, q;

    printf("Enter hash table size: ");
    if (scanf("%d", &m) != 1) return 0;
    HashTable* ht = createTable(m);

    printf("Enter number of elements to insert: ");
    if (scanf("%d", &n) != 1) return 0;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(ht, key);
    }

    printf("Enter number of search queries: ");
    if (scanf("%d", &q) != 1) return 0;
    for (int i = 0; i < q; i++) {
        printf("Enter key to search: ");
        scanf("%d", &key);
        int pos = search(ht, key);
        if (pos != -1) printf("Found at index: %d\n", pos);
        else printf("NOT FOUND\n");
    }

    free(ht->table);
    free(ht);
    return 0;
}