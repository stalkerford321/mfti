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

    char first_word[102];
    char second_word[102];

    fscanf(fin, "%101s %101s", first_word, second_word);

    int count_first[26] = {0};
    int count_second[26] = {0};

    for (int i = 0; first_word[i] != '\0'; i++)
    {
        count_first[first_word[i] - 'a']++;
    }

    for (int i = 0; second_word[i] != '\0'; i++)
    {
        count_second[second_word[i] - 'a']++;
    }

    int first_written = 1;

    for (int letter = 0; letter < 26; letter++)
    {
        if (count_first[letter] == 1 && count_second[letter] == 1)
        {
            if (!first_written)
            {
                fprintf(fout, " ");
            }
            fprintf(fout, "%c", 'a' + letter);
            first_written = 0;
        }
    }

    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);

    return 0;
}