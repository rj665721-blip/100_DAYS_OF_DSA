// Level Order Traversal

#include <stdlib.h>

// Definition for a binary tree node (typical LeetCode style).
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int maxNodes = 2000;
    int** result = (int**)malloc(maxNodes * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxNodes * sizeof(int));

    struct TreeNode** queue = (struct TreeNode**)malloc(maxNodes * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][i] = node->val;
            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        (*returnSize)++;
    }

    free(queue);
    return result;
}