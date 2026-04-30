// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

typedef struct {
    int u, v, w;
} Edge;
void bellmanFord(int n, int m, int src, Edge* edges) {
    double dist[n];
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE DETECTED\n");
            return;
        }
    }
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("  Node %d → UNREACHABLE\n", i);
        else
            printf("  Node %d → %.0f\n", i, dist[i]);
    }
}
int main() {
    int n, m, src;
    printf("Enter vertices, edges, source: ");
    scanf("%d %d %d", &n, &m, &src);
    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    bellmanFord(n, m, src, edges);
    free(edges);
    return 0;
}