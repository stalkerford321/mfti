#include <stdio.h>

int main(void) {
    int n, count = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (n % 2 == 0) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}