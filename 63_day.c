// Problem: Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>


int adj[100][100]; // adjacency list (stored as matrix of neighbors)
int adjCount[100]; // how many neighbors each vertex has
int visited[100];
int n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < adjCount[v]; i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

int main() {
    int edges, u, v, s;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    // Initialize
    for (int i = 0; i < n; i++)
        adjCount[i] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][adjCount[u]++] = v;  // u → v
        adj[v][adjCount[v]++] = u;  // v → u (undirected)
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);
    printf("\n");

    return 0;
}