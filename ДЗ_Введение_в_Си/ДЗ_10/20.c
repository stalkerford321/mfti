#include <stdio.h>
#include <string.h>

int is_palindrom(const char *s)
{
    int counts[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            counts[s[i] - 'a']++;
        }
    }

    int odd_count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] % 2 != 0)
        {
            odd_count++;
        }
    }

    return odd_count <= 1;
}

int main(void)
{
    FILE *fin = fopen("input.txt", "r");

    if (!fin)
    {
        return 1;
    }

    char s[1002];
    fgets(s, sizeof(s), fin);
    fclose(fin);

    size_t len = strlen(s);

    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
    {
        s[--len] = '\0';
    }

    if (is_palindrom(s))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}