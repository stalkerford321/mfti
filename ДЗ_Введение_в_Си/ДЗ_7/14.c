#include <stdio.h>

void print_odd(void) {
    static int first = 1; 
    int n;
    scanf("%d", &n);
    if (n == 0) {
        return;
    }
    if (n % 2 != 0) {
        if (!first) {
            printf(" ");
        }
        printf("%d", n);
        first = 0;
    }
    print_odd();
}
int main(void) {
    print_odd();
    printf("\n");
    return 0;
}