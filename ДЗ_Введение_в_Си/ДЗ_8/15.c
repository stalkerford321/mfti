#include <stdio.h>

int main(void) {
    int pos[10], neg[10];
    int np = 0, nn = 0;
    int x;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);
        if (x > 0) {
            pos[np++] = x;
        } else if (x < 0) {
            neg[nn++] = x;
        }
    }

    int first = 1;

    for (int i = 0; i < np; i++) {
        if (!first) printf(" ");
        printf("%d", pos[i]);
        first = 0;
    }

    for (int i = 0; i < nn; i++) {
        if (!first) printf(" ");
        printf("%d", neg[i]);
        first = 0;
    }

    printf("\n");
    return 0;
}