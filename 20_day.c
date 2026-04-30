// Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum = sum + arr[j];

            if (sum == 0) {
                count = count + 1;
            }
        }
    }

    return count;
}

int main() {
    int arr[] = {1, -1, 2, -2, 3};
    int n = 5;

    printf("%d", countZeroSumSubarrays(arr, n));
    return 0;
}