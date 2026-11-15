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

    char surname[1002];
    char name[1002];
    char patronymic[1002];

    fscanf(fin, "%1000s %1000s %1000s", surname, name, patronymic);

    fprintf(fout, "Hello, %s %s!\n", name, surname);

    fclose(fin);
    fclose(fout);

    return 0;
}