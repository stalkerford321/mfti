#include <stdio.h>

void print_simple(int n, int d) {
    if (n == 1) {
        return;
    }
    if (d > n / d) {
        printf("%d", n);
        return;
    }
    if (n % d == 0) {
        printf("%d", d);
        if (n / d != 1) {
            printf(" ");
        }
        print_simple(n / d, d);
    } else {
        print_simple(n, d + 1);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    print_simple(n, 2);
    printf("\n");
    return 0;
}