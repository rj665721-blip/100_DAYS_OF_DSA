// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>

int main() {
    int log1[100], log2[100], merged[200];
    int n, m;
    int i = 0, j = 0, k = 0;

    printf("Enter size of first log: ");
    scanf("%d", &n);

    printf("Enter elements of first log (sorted):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &log1[i]);

    printf("Enter size of second log: ");
    scanf("%d", &m);

    printf("Enter elements of second log (sorted):\n");
    for(j = 0; j < m; j++)
        scanf("%d", &log2[j]);

    i = 0;
    j = 0;

    while(i < n && j < m) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
}