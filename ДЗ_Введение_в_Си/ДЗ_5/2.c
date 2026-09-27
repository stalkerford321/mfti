#include <stdio.h>

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }
    for (int i = a; i <= b; i++) {
        if (i > a) {
            printf(" ");
        }
        printf("%d", i * i);
    }
    printf("\n");
    return 0;
}