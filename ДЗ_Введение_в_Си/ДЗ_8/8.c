#include <stdio.h>

int main(void) {
    int a[12];

    for (int i = 0; i < 12; i++) {
        scanf("%d", &a[i]);
    }

    for (int start = 0; start < 12; start += 4) {
        for (int i = 0; i < 2; i++) {
            int t = a[start + i];
            a[start + i] = a[start + 3 - i];
            a[start + 3 - i] = t;
        }
    }

    for (int i = 0; i < 12; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}