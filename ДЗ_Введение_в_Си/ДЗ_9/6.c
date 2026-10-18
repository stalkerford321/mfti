int is_two_same(int size, int a[])
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                return 1;
            }
        }
    }

    return 0;
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

    if (is_two_same(n, a)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
*/