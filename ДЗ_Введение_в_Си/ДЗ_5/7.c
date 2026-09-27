#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int d[10] = {0};
    while (n > 0) {
        int c = n % 10;
        if (d[c]) {
            printf("YES\n");
            return 0;
        }
        d[c] = 1;
        n /= 10;
    }
    printf("NO\n");
    return 0;
}