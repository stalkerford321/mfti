void sort_array(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

/*
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort_array(n, a);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
*/