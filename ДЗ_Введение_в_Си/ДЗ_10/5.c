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

    while ((ch = fgetc(fin)) != EOF)
    {
        switch (ch)
        {
            case 'a':
                fputc('b', fout);
                break;
            case 'b':
                fputc('a', fout);
                break;
            case 'A':
                fputc('B', fout);
                break;
            case 'B':
                fputc('A', fout);
                break;
            default:
                fputc(ch, fout);
                break;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}