int compression(int a[], int b[], int N)
{
    if (N <= 0) {
        return 0;
    }

    int result_size = 0;
    int expected_value = 0;
    int index = 0;

    if (a[0] == 1) {
        b[result_size++] = 0;
        expected_value = 1;
    } else {
        expected_value = 0;
    }

    while (index < N) {
        int series_length = 0;

        while (index < N && a[index] == expected_value) {
            series_length++;
            index++;
        }

        b[result_size++] = series_length;
        expected_value = 1 - expected_value;
    }

    return result_size;
}

/*
#include <stdio.h>

int main(void)
{
    int a[10000];
    int b[10000];
    int n = 0;
    int x;

    while (scanf("%d", &x) == 1) {
        a[n++] = x;
    }

    int m = compression(a, b, n);

    printf("[");
    for (int i = 0; i < m; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%d", b[i]);
    }
    printf("]\n");

    return 0;
}
*/