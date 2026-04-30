// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree. #include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[rear++] = curr->left;
            }
            i++;
        }
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[rear++] = curr->right;
            }
            i++;
        }
    }
    free(queue);
    return root;
}
struct TreeNode* lca(struct TreeNode* root, int p, int q) {
    if (root == NULL)           return NULL;
    if (root->val == p || root->val == q) return root;
    struct TreeNode* left  = lca(root->left,  p, q);
    struct TreeNode* right = lca(root->right, p, q);
    if (left != NULL && right != NULL) return root;   // LCA found
    return (left != NULL) ? left : right;
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter level-order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int p, q;
    printf("Enter two node values (p q): ");
    scanf("%d %d", &p, &q);
    struct TreeNode* root   = buildTree(arr, n);
    struct TreeNode* result = lca(root, p, q);
    if (result != NULL)
        printf("LCA(%d, %d) = %d\n", p, q, result->val);
    else
        printf("LCA not found\n");
    free(arr);
    return 0;
}