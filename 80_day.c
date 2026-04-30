#include <stdio.h>

#define INF 1000000000
#define MAXN 100

int dist[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);

    // Step 1: Read adjacency matrix, convert -1 → INF
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (i == j)
                dist[i][j] = 0;           // distance to self = 0
            else if (val == -1)
                dist[i][j] = INF;         // no edge → infinity
            else
                dist[i][j] = val;
        }
    }

    // Step 2: Floyd-Warshall
    // k = intermediate vertex being considered
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Avoid overflow: only relax if both paths are reachable
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print result matrix (-1 if unreachable)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1");
            else
                printf("%d", dist[i][j]);

            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}