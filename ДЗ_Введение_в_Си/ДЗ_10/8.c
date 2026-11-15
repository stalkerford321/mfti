#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    char s[1005];
    fgets(s, sizeof(s), fin);

    int numbers[500];
    int count = 0;

    int i = 0;
    int len = strlen(s);

    while (i < len)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int value = 0;

            while (i < len && s[i] >= '0' && s[i] <= '9')
            {
                value = value * 10 + (s[i] - '0');
                i++;
            }

            numbers[count++] = value;
        }
        else
        {
            i++;
        }
    }

    for (int a = 0; a < count - 1; a++)
    {
        for (int b = 0; b < count - 1 - a; b++)
        {
            if (numbers[b] > numbers[b + 1])
            {
                int temp = numbers[b];
                numbers[b] = numbers[b + 1];
                numbers[b + 1] = temp;
            }
        }
    }

    for (int k = 0; k < count; k++)
    {
        if (k > 0)
        {
            fprintf(fout, " ");
        }
        fprintf(fout, "%d", numbers[k]);
    }

    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);

    return 0;
}