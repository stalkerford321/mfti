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

    size_t i = 0;

    while (i < len)
    {
        if (i + 3 <= len && strncmp(s + i, "Cao", 3) == 0)
        {
            fputs("Ling", fout);
            i += 3;
        }
        else
        {
            fputc(s[i], fout);
            i++;
        }
    }

    fputc('\n', fout);

    fclose(fin);
    fclose(fout);

    return 0;
}