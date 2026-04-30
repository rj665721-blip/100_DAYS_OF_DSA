// Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = malloc(n * sizeof(int));
    int *stack  = malloc(n * sizeof(int));

    // Read queue
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    // Push all queue elements into stack
    int top = -1;
    for (int i = 0; i < n; i++)
        stack[++top] = queue[i];

    // Pop from stack back into queue (reverses order)
    for (int i = 0; i < n; i++)
        queue[i] = stack[top--];

    // Print reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d", queue[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");

    free(queue);
    free(stack);
    return 0;
}
