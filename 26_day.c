// Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL)
        return newNode;
    struct Node* current = head;

    // Move to last node
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Forward traversal
void traverseForward(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Backward traversal
void traverseBackward(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* current = head;

    // Move to last node
    while (current->next != NULL)
        current = current->next;

    // Traverse backward
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    traverseForward(head);
    traverseBackward(head);
    return 0;
}