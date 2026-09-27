#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0 0\n");
        return 0;
    }
    int min = 9, max = 0;
    while (n > 0) {
        int d = n % 10;
        if (d < min) min = d;
        if (d > max) max = d;
        n /= 10;
    }
    printf("%d %d\n", min, max);
    return 0;
}