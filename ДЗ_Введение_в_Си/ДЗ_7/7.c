#include <stdio.h>

void print_n_to_1(int n) {
    if (n == 1) {
        printf("1");
    } else {
        printf("%d ", n);
        print_n_to_1(n - 1);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    print_n_to_1(n);
    printf("\n");
    return 0;
}