// Check whether a given binary tree satisfies the Min-Heap property.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int isHeap = 1;

    for (int i = 0; i < n; i++) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left]) {
            isHeap = 0;
            break;
        }

        // Check right child
        if (right < n && arr[i] > arr[right]) {
            isHeap = 0;
            break;
        }
    }

    printf("%s\n", isHeap ? "YES" : "NO");
    return 0;
}