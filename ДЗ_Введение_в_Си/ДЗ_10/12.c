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

    int i = 0;

    while (i < (int)len)
    {
        while (i < (int)len && s[i] == ' ')
        {
            i++;
        }

        int start = i;

        while (i < (int)len && s[i] != ' ')
        {
            i++;
        }

        if (i > start)
        {
            for (int j = start; j < i; j++)
            {
                fputc(s[j], fout);
            }
            fputc('\n', fout);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}