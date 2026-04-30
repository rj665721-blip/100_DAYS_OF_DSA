

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
// Delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* previous = NULL;
    // If list is empty
    if (head == NULL)
        return head;
    // If key is at head
    if (head->data == key) {
        head = head->next;
        free(current);
        return head;
    }
    // Traverse list
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }
    // If key found
    if (current != NULL) {
        previous->next = current->next;
        free(current);
    }
    return head;
}
// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, value, key;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &key);
    head = deleteFirstOccurrence(head, key);
    printList(head);
    return 0;
}