// Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}
// Merge two sorted lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* merged = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            insertEnd(&merged, head1->data);
            head1 = head1->next;
        } else {
            insertEnd(&merged, head2->data);
            head2 = head2->next;
        }
    }
    // Remaining elements
    while (head1 != NULL) {
        insertEnd(&merged, head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        insertEnd(&merged, head2->data);
        head2 = head2->next;
    }
    return merged;
}
// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n1, n2, value;
    struct Node *head1 = NULL, *head2 = NULL;
    // First list
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }
    // Second list
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }
    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);
    return 0;
}