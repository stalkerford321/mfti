int sum_between_ab(int from, int to, int size, int a[])
{
    int left = from < to ? from : to;
    int right = from < to ? to : from;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= left && a[i] <= right)
        {
            sum += a[i];
        }
    }

    return sum;
}

/*
#include <stdio.h>

int main(void)
{
    int from, to, size;
    scanf("%d %d %d", &from, &to, &size);

    int a[1000];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d\n", sum_between_ab(from, to, size, a));

    return 0;
}
*/