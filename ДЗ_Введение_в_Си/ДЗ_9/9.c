void swap_negmax_last(int size, int a[])
{
    if (size <= 0)
    {
        return;
    }

    int negmax_index = -1;

    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (negmax_index == -1 || a[i] > a[negmax_index])
            {
                negmax_index = i;
            }
        }
    }

    if (negmax_index != -1)
    {
        int temp = a[negmax_index];
        a[negmax_index] = a[size - 1];
        a[size - 1] = temp;
    }
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

    swap_negmax_last(n, a);

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