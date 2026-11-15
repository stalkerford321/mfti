#include <stdio.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    int n;
    fscanf(fin, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            fprintf(fout, "%c", 'A' + i / 2);
        }
        else
        {
            int digit = ((i / 2) % 4 + 1) * 2;
            fprintf(fout, "%d", digit);
        }
    }

    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);

    return 0;
}