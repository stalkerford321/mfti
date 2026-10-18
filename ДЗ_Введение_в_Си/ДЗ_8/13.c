#include <stdio.h>

int main(void) {
    int a[10];
    int b[10];     
    int n = 0;    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        int x = a[i];
        if (x < 0) x = -x;     

        if ((x / 10) % 10 == 0) {
            b[n] = a[i];
            n++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}