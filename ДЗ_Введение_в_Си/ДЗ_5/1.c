#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }
    return 0;
}