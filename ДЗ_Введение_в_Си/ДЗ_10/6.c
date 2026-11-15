#include <stdio.h>
#include <string.h>

int is_palindrom(const char *str)
{
    int left = 0;
    int right = (int)strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left++;
        right--;
    }

    return 1;
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

    if (is_palindrom(s))
    {
        fprintf(fout, "YES\n");
    }
    else
    {
        fprintf(fout, "NO\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}