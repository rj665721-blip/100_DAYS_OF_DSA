//  Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

#include <stdio.h>
#include <stdlib.h>

// Node for linked list
struct Node {
    int dest;
    struct Node* next;
};

// Add edge to adjacency list
struct Node* addEdge(struct Node* head, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = head;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int directed;
    scanf("%d", &directed);

    for (int k = 0; k < m; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = addEdge(adj[u], v);
        if (!directed)
            adj[v] = addEdge(adj[v], u);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}