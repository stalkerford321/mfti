#include <stdio.h>

int main(void)
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout)
    {
        return 1;
    }

    int ch;
    int lowercase = 0;
    int uppercase = 0;

    while ((ch = fgetc(fin)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            lowercase++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            uppercase++;
        }
    }

    fprintf(fout, "%d %d\n", lowercase, uppercase);

    fclose(fin);
    fclose(fout);

    return 0;
}