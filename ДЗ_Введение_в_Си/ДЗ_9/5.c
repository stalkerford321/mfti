int find_max_array(int size, int a[])
{
    int max_value = a[0];

    for (int i = 1; i < size; i++) {
        if (a[i] > max_value) {
            max_value = a[i];
        }
    }

    return max_value;
}

/*
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", find_max_array(n, a));

    return 0;
}
*/