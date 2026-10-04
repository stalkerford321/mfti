#include <stdio.h>

void print_simple(int n) {
    int first = 1;
    for (int d = 2; d <= n / d; d++) {
        while (n % d == 0) {
            if (!first) printf(" ");
            printf("%d", d);
            first = 0;
            n /= d;
        }
    }
    if (n > 1) {
        if (!first) printf(" ");
        printf("%d", n);
    }

    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    print_simple(n);
    return 0;
}