#include <stdio.h>

double diagonal_average(int n, int a[][5])
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i][i];
    }

    return sum / n;
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

    double avg = diagonal_average(5, matrix);
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] > 0 && matrix[i][j] > avg)
            {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}