#include <stdio.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    int seen[256] = {0};
    int ch;

    while ((ch = fgetc(fin)) != EOF)
    {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
        {
            continue;
        }

        if (!seen[(unsigned char)ch])
        {
            seen[(unsigned char)ch] = 1;
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}