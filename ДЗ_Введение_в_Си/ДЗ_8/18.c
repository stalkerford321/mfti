#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int d = 2; d <= 9; d++) {
        printf("%d %d\n", d, n / d);
    }

    return 0;
}