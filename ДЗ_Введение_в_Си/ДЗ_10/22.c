#include <stdio.h>
#include <string.h>

int get_code(char c)
{
    switch (c)
    {
        case 'b': case 'f': case 'p': case 'v':
            return 1;
        case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
            return 2;
        case 'd': case 't':
            return 3;
        case 'l':
            return 4;
        case 'm': case 'n':
            return 5;
        case 'r':
            return 6;
        default:
            return 0;
    }
}

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    char word[25];
    fscanf(fin, "%24s", word);

    char result[5];
    int result_len = 0;

    result[result_len++] = word[0];

    int previous_code = 0;

    for (int i = 1; word[i] != '\0' && result_len < 4; i++)
    {
        int current_code = get_code(word[i]);

        if (current_code != 0)
        {
            if (current_code != previous_code)
            {
                result[result_len++] = '0' + current_code;
            }
            previous_code = current_code;
        }
    }

    while (result_len < 4)
    {
        result[result_len++] = '0';
    }

    result[4] = '\0';

    fprintf(fout, "%s\n", result);

    fclose(fin);
    fclose(fout);

    return 0;
}