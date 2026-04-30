// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>

int adj[100][100];
int adjCount[100];
int visited[100];
int stack[100];
int top = -1;
int V, E;
void dfs(int node) {
    visited[node] = 1;              // mark visited
    // Visit all neighbors first
    for (int i = 0; i < adjCount[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    // All neighbors done → push to stack
    stack[++top] = node;
}
void topologicalSort() {
    // Run DFS from every unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    // Print stack (top to bottom = topological order)
    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i]  = 0;
        adjCount[i] = 0;
    }
    printf("Enter edges (u v) meaning u → v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjCount[u]++] = v;
    }
    topologicalSort();
    return 0;
}