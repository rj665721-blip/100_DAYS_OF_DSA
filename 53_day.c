// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v; n->left = n->right = NULL;
    return n;
}

// Build tree from level-order input
Node* build(int* a, int n) {
    if (!n || a[0] == -1) return NULL;
    Node* nodes[1000] = {0};
    nodes[0] = newNode(a[0]);
    int q[1000], f = 0, r = 0, i = 1;
    q[r++] = 0;
    while (f < r && i < n) {
        int idx = q[f++];
        if (i < n && a[i] != -1) { nodes[2*idx+1] = newNode(a[i]); q[r++] = 2*idx+1; } i++;
        if (i < n && a[i] != -1) { nodes[2*idx+2] = newNode(a[i]); q[r++] = 2*idx+2; } i++;
        nodes[idx]->left  = nodes[2*idx+1];
        nodes[idx]->right = nodes[2*idx+2];
    }
    return nodes[0];
}

// BFS storing (node, col)
int   bfs_val[1000], bfs_col[1000], bfs_n = 0;

void bfs(Node* root) {
    Node* nq[1000]; int cq[1000], f = 0, r = 0;
    nq[r] = root; cq[r++] = 0;
    while (f < r) {
        Node* node = nq[f]; int col = cq[f++];
        bfs_val[bfs_n] = node->val;
        bfs_col[bfs_n++] = col;
        if (node->left)  { nq[r] = node->left;  cq[r++] = col - 1; }
        if (node->right) { nq[r] = node->right; cq[r++] = col + 1; }
    }
}

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    Node* root = build(a, n);
    bfs(root);

    // Find column range
    int lo = 0, hi = 0;
    for (int i = 0; i < bfs_n; i++) {
        if (bfs_col[i] < lo) lo = bfs_col[i];
        if (bfs_col[i] > hi) hi = bfs_col[i];
    }

    // Print column by column
    for (int col = lo; col <= hi; col++) {
        int first = 1;
        for (int i = 0; i < bfs_n; i++) {
            if (bfs_col[i] == col) {
                if (!first) printf(" ");
                printf("%d", bfs_val[i]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}