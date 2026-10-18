#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int digits[20], k = 0;
    while (n > 0) {
        digits[k++] = n % 10;
        n /= 10;
    }

    for (int i = k - 1; i >= 0; i--) {
        if (i != k - 1) printf(" ");
        printf("%d", digits[i]);
    }
    printf("\n");

    return 0;
}