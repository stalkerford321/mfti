#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a = 1, b = 1;
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", a);
        int t = a + b;
        a = b;
        b = t;
    }
    printf("\n");
    return 0;
}