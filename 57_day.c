// Convert a binary tree into its mirror image by swapping left and right children at every node.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val  = val;
    node->left = node->right = NULL;
    return node;
}

// ── Build tree from level-order input (-1 = NULL) ──────────────────
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0, i = 1;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[rear++] = curr->left;
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[rear++] = curr->right;
            }
            i++;
        }
    }
    return root;
}

// ── Mirror: swap left & right at every node ─────────────────────────
void mirror(struct TreeNode* root) {
    if (root == NULL) return;

    // Recurse on children first
    mirror(root->left);
    mirror(root->right);

    // Swap
    struct TreeNode* temp = root->left;
    root->left  = root->right;
    root->right = temp;
}

// ── Inorder traversal (Left → Root → Right) ────────────────────────
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// ── Main ────────────────────────────────────────────────────────────
int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter level-order (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    mirror(root);

    printf("Inorder of mirrored tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}