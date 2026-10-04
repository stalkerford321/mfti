#include <stdio.h>

int sum_to_n(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum_to_n(n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%d\n", sum_to_n(n));
    return 0;
}