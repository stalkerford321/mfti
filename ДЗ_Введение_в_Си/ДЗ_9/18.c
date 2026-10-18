// Задание отсутсвует на портале#include <stdio.h>

int find_max_in_row(int row[])
{
    int max_value = row[0];

    for (int j = 1; j < 10; j++)
    {
        if (row[j] > max_value)
        {
            max_value = row[j];
        }
    }

    return max_value;
}

int main(void)
{
    int matrix[10][10];
    long long sum = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        sum += find_max_in_row(matrix[i]);
    }

    printf("%lld\n", sum);

    return 0;
}