// Construct a binary tree from given preorder and inorder traversal arrays.

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
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int* preorder, int preSize, int* inorder, int inSize) {
    if (preSize == 0) return NULL;

    struct TreeNode* root = newNode(preorder[0]);

    int rootIdx = 0;
    for (int i = 0; i < inSize; i++) {
        if (inorder[i] == preorder[0]) {
            rootIdx = i;
            break;
        }
    }

    int leftSize = rootIdx;

    root->left  = buildTree(preorder + 1,             leftSize,
                            inorder,                  leftSize);

    root->right = buildTree(preorder + 1 + leftSize,  preSize - 1 - leftSize,
                            inorder  + rootIdx + 1,   preSize - 1 - leftSize);

    return root;
}

void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    postorder(root);
    printf("\n");

    return 0;
}