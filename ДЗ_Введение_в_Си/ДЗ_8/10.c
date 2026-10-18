#include <stdio.h>

int main(void) {
    int a[12];
    for (int i = 0; i < 12; i++) scanf("%d", &a[i]);

    for (int i = 8; i < 12; i++) printf("%d ", a[i]);
    for (int i = 0; i < 8; i++) {
        printf("%d", a[i]);
        if (i < 7) printf(" ");
    }
    printf("\n");
    return 0;
}