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

    if (fgets(s, sizeof(s), fin) == NULL)
    {
        fclose(fin);
        fclose(fout);
        return 0;
    }

    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[--len] = '\0';
    }

    size_t i = 0;

    while (i < len)
    {
        if (i + 4 <= len && strncmp(s + i, "Ling", 4) == 0)
        {
            fputs("Cao", fout);
            i += 4;
        }
        else
        {
            fputc(s[i], fout);
            i++;
        }
    }

    if (len > 0)
    {
        fputc('\n', fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}