// Construct a Binary Tree from the given level-order traversal.

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    TreeNode* queue[1000];          // queue stores node pointers
    int front = 0, rear = 0;
    TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;                      // index into input array
    while (front < rear && i < n) {
        TreeNode* curr = queue[front++];   // dequeue

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;    // enqueue for future children
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

void inorder(TreeNode* root, int* first) {
    if (root == NULL) return;
    inorder(root->left, first);
    if (!(*first)) printf(" ");     // space before every element except first
    printf("%d", root->val);
    *first = 0;
    inorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    TreeNode* root = buildTree(arr, n);
    int first = 1;
    inorder(root, &first);
    printf("\n");
    return 0;
}