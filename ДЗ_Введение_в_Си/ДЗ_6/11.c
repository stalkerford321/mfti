#include <stdio.h>

int nod(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", nod(a, b));
    return 0;
}