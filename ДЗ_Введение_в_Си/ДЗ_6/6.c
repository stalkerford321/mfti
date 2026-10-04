#include <stdio.h>

unsigned long long grains(int n) {
    return 1ULL << (n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%llu\n", grains(n));
    return 0;
}