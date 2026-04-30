// Problem: Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdbool.h>

int adj[100][100];
int adjCount[100];
int visited[100];
int recStack[100];  // recursion stack
int V;

bool dfs(int node) {

    visited[node]  = 1;   // mark visited
    recStack[node] = 1;   // add to recursion stack
    // Visit all neighbors
    for (int i = 0; i < adjCount[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor))          // cycle found in neighbor
                return true;
        }
        else if (recStack[neighbor]) {  // neighbor is in current path = CYCLE!
            return true;
        }
    }
    recStack[node] = 0;   // remove from recursion stack
    return false;
}

bool isCyclic() {
    // Run DFS from every unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i]  = 0;
        recStack[i] = 0;
        adjCount[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjCount[u]++] = v;   // directed: u → v
    }

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}