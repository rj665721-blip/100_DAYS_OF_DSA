#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (!node)
        return NULL;
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int height(struct TreeNode *root)
{
    if (root == NULL)
        return -1; // if you want height of empty tree as -1
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main(void)
{
    // Example tree:
    //     1
    //    / \
    //   2   3
    //  /   / \
    // 4   5   6
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    int h = height(root);
    printf("Height of binary tree: %d\n", h);

    return 0;
}