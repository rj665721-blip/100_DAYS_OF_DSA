// Construct a binary tree from given inorder and postorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIdx) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[(*postIdx)--];
    struct TreeNode* root = newNode(rootVal);

    // Find root's position in inorder
    int mid = inStart;
    while (inorder[mid] != rootVal) mid++;

    // Right subtree first, then left (postorder is consumed from end)
    root->right = build(inorder, mid + 1, inEnd, postorder, postIdx);
    root->left  = build(inorder, inStart, mid - 1, postorder, postIdx);

    return root;
}

void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int* inorder   = (int*)malloc(n * sizeof(int));
    int* postorder = (int*)malloc(n * sizeof(int));

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIdx = n - 1;
    struct TreeNode* root = build(inorder, 0, n - 1, postorder, &postIdx);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    free(inorder);
    free(postorder);
    return 0;
}