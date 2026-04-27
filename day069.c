/* Implement Dijkstra's Algorithm to find the shortest path from a source in a weighted graph. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

struct Edge {
    int to;
    int weight;
    struct Edge* next;
};

struct Graph {
    int numVertices;
    struct Edge** adjLists;
};

struct Node {
    int vertex;
    int dist;
};

struct PriorityQueue {
    struct Node* heap;
    int size;
    int capacity;
};

struct Edge* createEdge(int to, int weight) {
    struct Edge* newEdge = malloc(sizeof(struct Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Edge*));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Edge* newEdge = createEdge(v, w);
    newEdge->next = graph->adjLists[u];
    graph->adjLists[u] = newEdge;
    
    // For undirected graph
    newEdge = createEdge(u, w);
    newEdge->next = graph->adjLists[v];
    graph->adjLists[v] = newEdge;
}

void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist)
        smallest = left;
    if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->heap[smallest], &pq->heap[idx]);
        minHeapify(pq, smallest);
    }
}

void push(struct PriorityQueue* pq, int v, int d) {
    pq->heap[pq->size].vertex = v;
    pq->heap[pq->size].dist = d;
    int i = pq->size++;
    while (i != 0 && pq->heap[(i - 1) / 2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Node pop(struct PriorityQueue* pq) {
    struct Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    minHeapify(pq, 0);
    return root;
}

void dijkstra(struct Graph* graph, int start) {
    int n = graph->numVertices;
    int* dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INF;

    struct PriorityQueue* pq = malloc(sizeof(struct PriorityQueue));
    pq->heap = malloc(n * n * sizeof(struct Node)); // Overkill capacity for simplicity
    pq->size = 0;

    dist[start] = 0;
    push(pq, start, 0);

    while (pq->size > 0) {
        struct Node top = pop(pq);
        int u = top.vertex;
        int d = top.dist;

        if (d > dist[u]) continue;

        struct Edge* edge = graph->adjLists[u];
        while (edge) {
            int v = edge->to;
            int weight = edge->weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(pq, v, dist[v]);
            }
            edge = edge->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("%d: INF\n", i);
        else printf("%d: %d\n", i, dist[i]);
    }

    free(dist);
    free(pq->heap);
    free(pq);
}

int main() {
    int n, m, start;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }
    scanf("%d", &start);

    dijkstra(graph, start);

    return 0;
}