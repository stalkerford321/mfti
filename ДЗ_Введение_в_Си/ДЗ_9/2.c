#include <stdlib.h>

void sort_even_odd(int n, int a[]) {
    int *tmp = malloc(n * sizeof(int));
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            tmp[k++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            tmp[k++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }

    free(tmp);
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

    sort_even_odd(n, a);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
*/