#include <stdio.h>

void print_num(int num) {
    if (num < 10) {
        printf("%d", num);
    } else {
        print_num(num / 10);     
        printf(" %d", num % 10); 
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    print_num(n);
    printf("\n");
    return 0;
}