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

    int count = 0;
    int in_word = 0;
    int word_ends_with_a = 0;

    for (size_t i = 0; i <= len; i++)
    {
        char ch = (i < len) ? s[i] : ' ';

        if (ch == ' ')
        {
            if (in_word && word_ends_with_a)
            {
                count++;
            }
            in_word = 0;
            word_ends_with_a = 0;
        }
        else
        {
            in_word = 1;
            word_ends_with_a = (ch == 'a');
        }
    }

    fprintf(fout, "%d\n", count);

    fclose(fin);
    fclose(fout);

    return 0;
}