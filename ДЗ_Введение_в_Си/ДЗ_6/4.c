#include <stdio.h>

int f(int x) {
    if (x < -2) {
        return 4;
    } else if (x < 2) {
        return x * x;
    } else {
        return x * x + 4 * x + 5;
    }
}

int main(void) {
    int x, max = 0, first = 1;
    while (scanf("%d", &x) == 1 && x != 0) {
        int y = f(x);
        if (first || y > max) {
            max = y;
            first = 0;
        }
    }
    printf("%d\n", max);
    return 0;
}