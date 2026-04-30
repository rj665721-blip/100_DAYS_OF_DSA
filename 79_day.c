// Problem Statement : Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005
#define MAXE 200005

// ─── Adjacency List ───────────────────────────────
int head[MAXN], nxt[MAXE], to[MAXE], wt[MAXE], cnt = 0;

void addEdge(int u, int v, int w) {
    cnt++;
    to[cnt]  = v;
    wt[cnt]  = w;
    nxt[cnt] = head[u];
    head[u]  = cnt;
}

// ─── Min-Heap (Priority Queue) ────────────────────
typedef struct { int dist, node; } Node;

Node heap[MAXE];
int heapSize = 0;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void push(int d, int u) {
    heap[++heapSize] = (Node){d, u};
    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int smallest = i;
        if (2*i   <= heapSize && heap[2*i].dist   < heap[smallest].dist) smallest = 2*i;
        if (2*i+1 <= heapSize && heap[2*i+1].dist < heap[smallest].dist) smallest = 2*i+1;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;
}

// ─── Dijkstra ─────────────────────────────────────
long long dist[MAXN];
int visited[MAXN];

void dijkstra(int src, int n) {
    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX, visited[i] = 0;
    dist[src] = 0;
    push(0, src);

    while (heapSize > 0) {
        Node cur = pop();
        int u = cur.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e], w = wt[e];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(dist[v], v);
            }
        }
    }
}

// ─── Main ─────────────────────────────────────────
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);   // undirected; remove if directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(src, n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) printf("INF");
        else printf("%lld", dist[i]);
        if (i < n) printf(" ");
    }
    printf("\n");

    return 0;
}