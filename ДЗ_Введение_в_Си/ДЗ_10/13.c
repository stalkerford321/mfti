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

    int dot_index = -1;
    int slash_index = -1;

    for (int i = 0; i < (int)len; i++)
    {
        if (s[i] == '.')
        {
            dot_index = i;
        }
        else if (s[i] == '/')
        {
            slash_index = i;
        }
    }

    if (dot_index != -1 && dot_index > slash_index)
    {
        s[dot_index] = '\0';
        len = dot_index;
    }

    fprintf(fout, "%s.html\n", s);

    fclose(fin);
    fclose(fout);

    return 0;
}