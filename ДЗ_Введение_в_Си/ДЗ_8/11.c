#include <stdio.h>

int last_digit(int x) {
    int d = x % 10;
    if (d < 0) d = -d;
    return d;
}

int main(void) {
    int a[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - 1 - i; j++) {
            if (last_digit(a[j]) > last_digit(a[j + 1])) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}