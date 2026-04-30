// Given integers a and b, compute a^b using recursion without using pow() function.

#include <stdio.h>

long long power(int a, int b) {
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    scanf("%d", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    printf("%d^%d = %lld\n", a, b, power(a, b));

    return 0;
}
