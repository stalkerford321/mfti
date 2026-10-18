int count_bigger_abs(int n, int a[])
{
    if (n <= 0)
    {
        return 0;
    }

    int max_value = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_value)
        {
            max_value = a[i];
        }
    }

    long long threshold = max_value;
    if (threshold < 0)
    {
        threshold = -threshold;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        long long value = a[i];
        if (value < 0)
        {
            value = -value;
        }

        if (value > threshold)
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
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("%d\n", count_bigger_abs(n, a));

    return 0;
}
*/