#include <stdio.h>
#include <string.h>

void swap_adjacent_pairs(char s[])
{
    int positions[1002];
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            positions[count++] = i;
        }
    }

    for (int i = 0; i + 1 < count; i += 2)
    {
        int left = positions[i];
        int right = positions[i + 1];

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
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

    char s[1002];
    fgets(s, sizeof(s), fin);

    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[--len] = '\0';
    }

    swap_adjacent_pairs(s);

    fprintf(fout, "%s\n", s);

    fclose(fin);
    fclose(fout);

    return 0;
}