// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    
    curr->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    // Move longer list ahead
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }
    
    // Move both together
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return NULL;
}

int main() {
    int n, m, i, val;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head1, val);
    }

    // Second list
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        append(&head2, val);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}