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

    char longest[1002] = "";
    size_t max_length = 0;

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

        int word_length = i - start;

        if (word_length > (int)max_length)
        {
            max_length = word_length;
            strncpy(longest, s + start, max_length);
            longest[max_length] = '\0';
        }
    }

    fprintf(fout, "%s\n", longest);

    fclose(fin);
    fclose(fout);

    return 0;
}