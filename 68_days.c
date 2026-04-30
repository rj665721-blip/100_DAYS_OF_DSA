// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

struct Node* adj[100];   // adjacency list
int inDegree[100];       // in-degree of each node
int queue[100];          // simple circular queue
int front, rear;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
    inDegree[v]++;
}

void kahnTopSort(int V) {
    front = 0;
    rear = 0;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int result[100];
    int idx = 0;
    while (front < rear) {
        int u = queue[front++];
        result[idx++] = u;
        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                queue[rear++] = v;   // now ready to process
            }
            temp = temp->next;
        }
    }
    if (idx != V) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }
    printf("Topological Order: ");
    for (int i = 0; i < idx; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int V = 6;
    memset(adj, 0, sizeof(adj));
    memset(inDegree, 0, sizeof(inDegree));
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
    kahnTopSort(V);
    return 0;
}