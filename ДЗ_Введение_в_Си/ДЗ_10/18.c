#include <stdio.h>
#include <string.h>

void remove_extra_spaces(char s[])
{
    int write_index = 0;
    int read_index = 0;

    while (s[read_index] == ' ')
    {
        read_index++;
    }

    while (s[read_index] != '\0')
    {
        if (s[read_index] != ' ')
        {
            s[write_index++] = s[read_index];
        }
        else
        {
            s[write_index++] = ' ';

            while (s[read_index] == ' ')
            {
                read_index++;
            }

            continue;
        }

        read_index++;
    }

    if (write_index > 0 && s[write_index - 1] == ' ')
    {
        write_index--;
    }

    s[write_index] = '\0';
}

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

    remove_extra_spaces(s);

    fprintf(fout, "%s\n", s);

    fclose(fin);
    fclose(fout);

    return 0;
}