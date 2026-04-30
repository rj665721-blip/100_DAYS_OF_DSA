// Problem Statement : Using DFS or BFS, count number of connected components.

#include <stdio.h>
#include <string.h>

#define MAXN 1005

int adj[MAXN][MAXN]; // adjacency matrix
int visited[MAXN];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);   // explore entire component
            count++;  // one full component done
        }
    }

    printf("%d\n", count);
    return 0;
}