#include <stdio.h>

int main(void)
{
    char letter;
    int digit;

    scanf(" %c%d", &letter, &digit);

    int column = letter - 'A';
    int row = digit - 1;

    if ((column + row) % 2 == 0)
    {
        printf("BLACK\n");
    }
    else
    {
        printf("WHITE\n");
    }

    return 0;
}