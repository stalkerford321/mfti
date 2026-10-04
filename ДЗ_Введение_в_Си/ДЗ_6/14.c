#include <stdio.h>

int is_even_digit_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum % 2 == 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (is_even_digit_sum(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}