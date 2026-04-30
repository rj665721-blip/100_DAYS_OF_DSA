// Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>

int main() {
    int nums[] = {1,2,2,3,1,4};
    int n = sizeof(nums)/sizeof(nums[0]);

    for(int i = 0; i < n; i++) {
        int count = 1;

        int alreadyCounted = 0;
        for(int k = 0; k < i; k++) {
            if(nums[i] == nums[k]) {
                alreadyCounted = 1;
                break;
            }
        }
        if(alreadyCounted) continue;

        for(int j = i + 1; j < n; j++) {
            if(nums[i] == nums[j])
                count++;
        }

        printf("%d", nums[i], count);
    }

    return 0;
}
