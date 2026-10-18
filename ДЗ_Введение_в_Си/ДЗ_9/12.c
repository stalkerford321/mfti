void change_max_min(int size, int a[])
{
    if (size <= 0)
    {
        return;
    }

    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[min_index])
        {
            min_index = i;
        }
        if (a[i] > a[max_index])
        {
            max_index = i;
        }
    }

    int temp = a[min_index];
    a[min_index] = a[max_index];
    a[max_index] = temp;
}

/*
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    change_max_min(n, a);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
*/