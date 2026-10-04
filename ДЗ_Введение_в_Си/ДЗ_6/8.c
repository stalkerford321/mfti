#include <stdio.h>

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int main(void) {
    int c;
    while ((c = getchar()) != '.' && c != EOF) {
        putchar(to_upper(c));
    }
    putchar('\n');
    return 0;
}