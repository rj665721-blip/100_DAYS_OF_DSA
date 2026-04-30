// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) return 0;
    struct Node *head = NULL, *last = NULL, *newNode = NULL;
    // Create list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    int k;
    scanf("%d", &k);
    // If only one node
    if (head == NULL || head->next == NULL) {
        struct Node* ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        return 0;
    }
    // Count length
    int length = 1;
    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        length++;
    }
    // Make circular
    ptr->next = head;
    k = k % length;
    if (k == 0) {
        ptr->next = NULL; // break circle
    } else {
        int steps = length - k;
        struct Node* current = head;
        for (int i = 1; i < steps; i++) {
            current = current->next;
        }
        head = current->next;
        current->next = NULL;
    }
    // Print rotated list
    struct Node* printPtr = head;
    while (printPtr != NULL) {
        printf("%d ", printPtr->data);
        printPtr = printPtr->next;
    }
    return 0;
}