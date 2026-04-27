/* Print topological ordering of a Directed Acyclic Graph (DAG) using DFS. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
}

void topologicalSortDFS(struct Graph* graph, int v, int* stack, int* top) {
    graph->visited[v] = true;

    struct Node* temp = graph->adjLists[v];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            topologicalSortDFS(graph, temp->vertex, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int* stack = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (!graph->visited[i]) {
            topologicalSortDFS(graph, i, stack, &top);
        }
    }

    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    free(stack);
    return 0;
}