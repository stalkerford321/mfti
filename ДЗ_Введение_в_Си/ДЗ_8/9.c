#include <stdio.h>

int main(void) {
    int a[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    int last = a[9];            
    for (int i = 9; i > 0; i--) {
        a[i] = a[i - 1];          
    }
    a[0] = last;                 

    for (int i = 0; i < 10; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}