#include <stdio.h>

void print_range(int a, int b) {
    printf("%d", a);
    if (a == b) {
        return;
    }
    printf(" ");
    if (a < b) {
        print_range(a + 1, b);
    } else {
        print_range(a - 1, b);
    }
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    print_range(a, b);
    printf("\n");
    return 0;
}