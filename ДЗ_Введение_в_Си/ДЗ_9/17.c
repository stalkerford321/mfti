#include <stdio.h>

int matrix_trace(int n, int a[5][5])
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i][i];
    }

    return sum;
}

int main(void)
{
    int matrix[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%d\n", matrix_trace(5, matrix));

    return 0;
}