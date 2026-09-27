#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int first = 1;
    for (int i = 10; i <= n; i++) {
        int x = i;
        int sum = 0, prod = 1;
        while (x > 0) {
            int d = x % 10;
            sum += d;
            prod *= d;
            x /= 10;
        }
        if (sum == prod) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}