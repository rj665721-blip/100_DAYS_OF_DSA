// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int degree[MAX];  // kitne neighbours hain
bool visited[MAX];
int V, E;

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < degree[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {  // visited + not parent = CYCLE
            return true;
        }
    }
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    printf("Vertices: ");
    scanf("%d", &V);
    printf("Edges: ");
    scanf("%d", &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        degree[i] = 0;
        visited[i] = false;
    }

    printf("Edges daalo (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
