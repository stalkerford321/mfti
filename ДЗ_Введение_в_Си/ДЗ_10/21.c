#include <stdio.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    int ch;
    int stars = 0;

    while ((ch = fgetc(fin)) != EOF)
    {
        if (ch == '*')
        {
            stars++;
        }
    }

    int height = 0;
    int total = 0;

    while (total + height + 1 <= stars)
    {
        height++;
        total += height;
    }

    if (stars == 0 || total != stars)
    {
        fprintf(fout, "NO\n");
    }
    else
    {
        for (int row = 1; row <= height; row++)
        {
            int spaces_count = height - row;
            for (int s = 0; s < spaces_count; s++)
            {
                fputc(' ', fout);
            }

            for (int star = 0; star < row; star++)
            {
                if (star > 0)
                {
                    fputc(' ', fout);
                }
                fputc('*', fout);
            }

            fputc('\n', fout);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}