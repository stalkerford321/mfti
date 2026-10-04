#include <stdio.h>

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", my_abs(n));
    return 0;
}