int count_between(int from, int to, int size, int a[])
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
        {
            count++;
        }
    }

    return count;
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

    printf("%d\n", count_between(from, to, size, a));

    return 0;
}
*/