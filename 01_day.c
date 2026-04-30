//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>

int main() {
    int a[100];
    int size, value, position;
    int index;

    printf("Enter size: ");
    scanf("%d", &size);

    for(index = 0; index < size; index++) {
        scanf("%d", &a[index]);
    }

    printf("Enter value and position: ");
    scanf("%d %d", &value, &position);

    for(index = size; index >= position; index--) {
        a[index] = a[index - 1];
    }

    a[position - 1] = value;
    size++;

    for(index = 0; index < size; index++) {
        printf("%d ", a[index]);
    }

    return 0;
}
