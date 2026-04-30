/* Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int heap[MAX_SIZE];
int heapSize = 0;

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Move newly inserted element UP to restore heap property
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Move root DOWN after extractMin to restore heap property
void heapifyDown(int index) {
    while (1) {
        int left    = 2 * index + 1;
        int right   = 2 * index + 2;
        int smallest = index;

        if (left  < heapSize && heap[left]  < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert x into the heap
void insert(int x) {
    heap[heapSize] = x;
    heapifyUp(heapSize);
    heapSize++;
}

// Remove and return the minimum (root)
int extractMin() {
    if (heapSize == 0) return -1;

    int min = heap[0];
    heap[0] = heap[heapSize - 1]; // Move last element to root
    heapSize--;
    heapifyDown(0);               // Fix heap downward

    return min;
}

// Return minimum without removing
int peek() {
    if (heapSize == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {          // insert
            int x;
            scanf("%d", &x);
            insert(x);

        } else if (op[0] == 'e') {   // extractMin
            printf("%d\n", extractMin());

        } else if (op[0] == 'p') {   // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}
