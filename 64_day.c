// Perform BFS from a given source using queue.

#include <stdio.h>
#include <string.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int adjSize[MAX];   // how many neighbors each node has

// Queue
int queue[MAX];
int front = 0, back = 0;

int visited[MAX];

void addEdge(int u, int v) {
    adj[u][adjSize[u]++] = v;
    adj[v][adjSize[v]++] = u;   // undirected
}

void bfs(int s, int n) {
    memset(visited, 0, sizeof(visited));

    // Enqueue source
    queue[back++] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (front < back) {
        int node = queue[front++];   // Dequeue
        printf("%d ", node);

        // Visit all unvisited neighbors
        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[back++] = neighbor;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    memset(adjSize, 0, sizeof(adjSize));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int s;
    printf("Enter source node: ");
    scanf("%d", &s);

    bfs(s, n);

    return 0;
}