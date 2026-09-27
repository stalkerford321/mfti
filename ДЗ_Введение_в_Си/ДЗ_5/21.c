#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != '.') {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        putchar(c);
    }
    putchar('\n');
    return 0;
}