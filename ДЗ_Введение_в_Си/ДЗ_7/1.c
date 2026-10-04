#include <stdio.h>

void print_1_to_n(int n) {
    if (n == 0) {
        return;
    }
    print_1_to_n(n - 1);  
    if (n > 1) {
        printf(" ");
    }
    printf("%d", n);
}

int main(void) {
    int n;
    scanf("%d", &n);
    print_1_to_n(n);
    printf("\n");
    return 0;
}