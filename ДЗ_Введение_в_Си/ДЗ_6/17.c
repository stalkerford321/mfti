#include <stdio.h>

int is_happy_number(int n) {
    if (n == 0) return 1;
    int sum = 0;
    int prod = 1;
    while (n > 0) {
        int d = n % 10;
        sum += d;
        prod *= d;
        n /= 10;
    }
    return sum == prod;
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (is_happy_number(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}