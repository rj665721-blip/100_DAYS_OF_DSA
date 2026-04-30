// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// ── Min-Heap (priority queue) ─────────────────────────────────────────────────
typedef struct
{
    int dist, node;
} HeapNode;

typedef struct
{
    HeapNode *data;
    int size, cap;
} MinHeap;

MinHeap *createHeap(int cap)
{
    MinHeap *h = malloc(sizeof(MinHeap));
    h->data = malloc(cap * sizeof(HeapNode));
    h->size = 0;
    h->cap = cap;
    return h;
}

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *h, int dist, int node)
{
    int i = h->size++;
    h->data[i] = (HeapNode){dist, node};
    // Bubble up
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (h->data[p].dist <= h->data[i].dist)
            break;
        swap(&h->data[p], &h->data[i]);
        i = p;
    }
}

HeapNode pop(MinHeap *h)
{
    HeapNode top = h->data[0];
    h->data[0] = h->data[--h->size];
    // Bubble down
    int i = 0;
    while (1)
    {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < h->size && h->data[l].dist < h->data[smallest].dist)
            smallest = l;
        if (r < h->size && h->data[r].dist < h->data[smallest].dist)
            smallest = r;
        if (smallest == i)
            break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return top;
}

// ── Adjacency List ────────────────────────────────────────────────────────────
#define MAXN 105
#define MAXE 10005

int head[MAXN], nxt[MAXE], to[MAXE], wt[MAXE], ecnt;

void initGraph()
{
    memset(head, -1, sizeof(head));
    ecnt = 0;
}

void addEdge(int u, int v, int w)
{
    to[ecnt] = v;
    wt[ecnt] = w;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

// ── Dijkstra ──────────────────────────────────────────────────────────────────
int networkDelayTime(int **times, int timesSize, int *timesColSize, int n, int k)
{
    initGraph();
    for (int i = 0; i < timesSize; i++)
        addEdge(times[i][0], times[i][1], times[i][2]);

    int dist[MAXN];
    bool visited[MAXN];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX, visited[i] = false;
    dist[k] = 0;

    // Heap capacity = timesSize (max edges we'll push) + 1
    MinHeap *pq = createHeap(timesSize + 1);
    push(pq, 0, k);

    while (pq->size > 0)
    {
        HeapNode cur = pop(pq); // extract min-dist node
        int u = cur.node;

        if (visited[u])
            continue; // stale entry, skip
        visited[u] = true;

        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e], w = wt[e];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(pq, dist[v], v); // push updated distance
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > ans)
            ans = dist[i];
    }
    return ans;
}