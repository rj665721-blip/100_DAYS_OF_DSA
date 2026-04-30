// Print the nodes visible when the binary tree is viewed from the right side.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* queue[100];
    int front = 0, rear = 0;

    struct node* root = createnode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = createnode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createnode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void rightSideView(struct node* root) {
    if (!root) return;

    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct node* curr = queue[front++];

            if (i == levelSize - 1)
                printf("%d ", curr->data);

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter level-order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    printf("Right Side View: ");
    rightSideView(root);

    return 0;
}