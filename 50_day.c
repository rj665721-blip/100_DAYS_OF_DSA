#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        if (newNode == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val == root->val)
        return root;
    else if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main(void)
{
    struct TreeNode *root = NULL;
    int values[] = {4, 2, 7, 1, 3};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; ++i)
    {
        root = insertIntoBST(root, values[i]);
    }

    int target = 3;
    struct TreeNode *node = searchBST(root, target);
    if (node != NULL)
        printf("Found %d in BST\n", node->val);
    else
        printf("%d not found in BST\n", target);

    return 0;
}