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

    char s[1002];
    fgets(s, sizeof(s), fin);

    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[--len] = '\0';
    }

    if (len == 0)
    {
        fclose(fin);
        fclose(fout);
        return 0;
    }

    char last = s[len - 1];
    int first = 1;

    for (size_t i = 0; i < len - 1; i++)
    {
        if (s[i] == last)
        {
            if (!first)
            {
                fprintf(fout, " ");
            }
            fprintf(fout, "%zu", i);
            first = 0;
        }
    }

    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);

    return 0;
}