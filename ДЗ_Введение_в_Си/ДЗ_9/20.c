#include <stdio.h>
#include <stdlib.h>

long long product_of_digits(long long number, int want_odd)
{
    number = llabs(number);
    long long product = 1;
    int found = 0;

    if (number == 0)
    {
        if (!want_odd)
        {
            return 0; // цифра 0 является чётной
        }
        return 0;
    }

    while (number > 0)
    {
        int digit = number % 10;

        if (want_odd)
        {
            if (digit % 2 == 1)
            {
                product *= digit;
                found = 1;
            }
        }
        else
        {
            if (digit % 2 == 0)
            {
                product *= digit;
                found = 1;
            }
        }

        number /= 10;
    }

    return found ? product : 0;
}

int main(void)
{
    long long a[10];
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%lld", &a[i]);

        if (a[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }

    if (even_count > odd_count)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] % 2 != 0)
            {
                a[i] = product_of_digits(a[i], 1);
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] % 2 == 0)
            {
                a[i] = product_of_digits(a[i], 0);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%lld", a[i]);
    }
    printf("\n");

    return 0;
}