// Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending order of exponent
struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    // If list is empty OR exponent greater than head
    if (head == NULL || e > head->exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    // Traverse to correct position
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }

    // If same exponent, add coefficients
    if (temp->next != NULL && temp->next->exp == e) {
        temp->next->coeff += c;
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->coeff != 0) {
            if (temp->exp == 0)
                printf("%d", temp->coeff);
            else if (temp->exp == 1)
                printf("%dx", temp->coeff);
            else
                printf("%dx^%d", temp->coeff, temp->exp);

            if (temp->next != NULL)
                printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printPolynomial(head);

    return 0;
}