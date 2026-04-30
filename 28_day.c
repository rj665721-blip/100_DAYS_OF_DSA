// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0) {
        return 0;
    }
    struct Node *head = NULL;
    struct Node *last = NULL;
    struct Node *newNode = NULL;
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
    // Make list circular
    last->next = head;
    // Traversal
    struct Node* ptr = head;
    if (head != NULL) {
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
    return 0;
}