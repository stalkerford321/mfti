#include <stdio.h>

int main(void)
{
    char s[1005];
    scanf("%1004s", s);

    int i = 0;
    while (s[i] != '.' && s[i] != '\0')
    {
        char current = s[i];
        int count = 0;

        while (s[i] == current)
        {
            count++;
            i++;
        }

        printf("%c%d", current, count);
    }

    printf("\n");
    return 0;
}