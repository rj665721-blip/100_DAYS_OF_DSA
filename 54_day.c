// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val  = val;
    node->left = node->right = NULL;
    return node;
}
TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
void zigzagTraversal(TreeNode* root) {
    if (!root) return;
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int level = 0;
    while (front < rear) {
        int size = rear - front;          // Nodes at current level
        int levelArr[1000];

        for (int i = 0; i < size; i++) {
            TreeNode* node = queue[front++];
            if (level % 2 == 0)
                levelArr[i]            = node->val;
            else
                levelArr[size - 1 - i] = node->val;
            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        for (int i = 0; i < size; i++) {
            printf("%d", levelArr[i]);
            if (i < size - 1) printf(" ");
        }
        printf("\n");
        level++;
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[1000];
    printf("Enter level-order values (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    TreeNode* root = buildTree(arr, n);
    printf("\nZigzag Level Order Traversal:\n");
    zigzagTraversal(root);
    return 0;
}