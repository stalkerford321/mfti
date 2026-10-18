#include <stdio.h>

void print_min_sum_indices(int a[], int n)
{
    long long min_sum = (long long)a[0] + a[1];
    int min_i = 0;
    int min_j = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long current_sum = (long long)a[i] + a[j];

            if (current_sum < min_sum)
            {
                min_sum = current_sum;
                min_i = i;
                min_j = j;
            }
        }
    }

    printf("%d %d\n", min_i, min_j);
}

int main(void)
{
    int a[30];

    for (int i = 0; i < 30; i++)
    {
        scanf("%d", &a[i]);
    }

    print_min_sum_indices(a, 30);

    return 0;
}