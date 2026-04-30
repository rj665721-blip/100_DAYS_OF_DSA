// Check whether a given binary tree is symmetric around its center.


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* n = malloc(sizeof(struct TreeNode));
    n->val = val; n->left = n->right = NULL;
    return n;
}

// Build tree from level-order input (-1 = NULL)
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode** queue = malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0, i = 1;
    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];
        if (i < n && arr[i] != -1) { curr->left  = newNode(arr[i]); queue[rear++] = curr->left;  } i++;
        if (i < n && arr[i] != -1) { curr->right = newNode(arr[i]); queue[rear++] = curr->right; } i++;
    }
    free(queue);
    return root;
}

int isMirror(struct TreeNode* l, struct TreeNode* r) {
    if (!l && !r) return 1;
    if (!l || !r) return 0;
    return (l->val == r->val)
        && isMirror(l->left,  r->right)
        && isMirror(l->right, r->left);
}

int isSymmetric(struct TreeNode* root) {
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);
    printf("%s\n", isSymmetric(root) ? "YES" : "NO");

    free(arr);
    return 0;
}