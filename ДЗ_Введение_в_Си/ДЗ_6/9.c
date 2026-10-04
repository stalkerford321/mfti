#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%llu\n", factorial(n));
    return 0;
}