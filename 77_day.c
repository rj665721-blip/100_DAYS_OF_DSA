// Problem Statement:- Using BFS or DFS, check if the entire graph is connected.

#include <stdio.h>
#include <string.h>

#define MAXN 1005

// ── Adjacency List ────────────────────────────────────────
int head[MAXN];
int to[MAXN * 2];
int nxt[MAXN * 2];
int edge_cnt = 0;

void add_edge(int u, int v) {
    to[edge_cnt]  = v;
    nxt[edge_cnt] = head[u];
    head[u]       = edge_cnt++;
}

// ── BFS ───────────────────────────────────────────────────
int visited[MAXN];
int queue[MAXN];

int bfs(int start, int n) {
    int front = 0, rear = 0;
    int count = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = queue[front++];
        count++;

        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return count;  // total nodes reachable from start
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    memset(head, -1, sizeof(head));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);  // undirected
        add_edge(v, u);
    }

    int reachable = bfs(1, n);  // start BFS from node 1

    if (reachable == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}