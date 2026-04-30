//  Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {-8, -66, -60, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = 1000000;
    int num1, num2;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements closest to zero: %d and %d\n", num1, num2);

    return 0;
}
