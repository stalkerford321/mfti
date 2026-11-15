#include <stdio.h>
#include <string.h>

void build_palindrome(const char *s, char *result)
{
    int counts[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        counts[s[i] - 'a']++;
    }

    int left_index = 0;
    int right_index = 0;

    for (int i = 0; i < 26; i++)
    {
        int pairs = counts[i] / 2;
        for (int j = 0; j < pairs; j++)
        {
            result[left_index++] = 'a' + i;
        }
    }

    right_index = left_index;

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] % 2 != 0)
        {
            result[left_index++] = 'a' + i;
            break;
        }
    }

    for (int i = 25; i >= 0; i--)
    {
        int pairs = counts[i] / 2;
        for (int j = 0; j < pairs; j++)
        {
            result[left_index++] = 'a' + i;
        }
    }

    result[left_index] = '\0';
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

    char result[1002];
    build_palindrome(s, result);

    fprintf(fout, "%s\n", result);

    fclose(fin);
    fclose(fout);

    return 0;
}