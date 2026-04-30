//  Problem: Build a graph with n vertices and m edges using adjacency matrix representation.

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int directed;
    scanf("%d", &directed);

    for (int k = 0; k < m; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (!directed)
            graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}