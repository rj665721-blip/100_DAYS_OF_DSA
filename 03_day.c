// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int arr[100], n, k;
    int i, comparisons = 0, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Element found at position %d\n", i + 1);
    else
        printf("Element not found\n");

    printf("Total comparisons: %d\n", comparisons);

    return 0;
}
