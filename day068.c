/* Implement topological sorting using in-degree array and queue (Kahn's Algorithm). */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* inDegree;
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
    graph->inDegree = calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
    struct Node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
    graph->inDegree[d]++;
}

void kahnsTopologicalSort(struct Graph* graph) {
    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int* result = malloc(graph->numVertices * sizeof(int));

    while (front < rear) {
        int u = queue[front++];
        result[count++] = u;

        struct Node* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            graph->inDegree[v]--;
            if (graph->inDegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != graph->numVertices) {
        printf("Graph contains a cycle!\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    free(queue);
    free(result);
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

    kahnsTopologicalSort(graph);

    return 0;
}