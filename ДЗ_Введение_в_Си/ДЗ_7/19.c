#include <stdio.h>

int acounter(void) {
    int c = getchar();
    if (c == '.' || c == EOF) {
        return 0;
    }
    return (c == 'a') + acounter();
}

int main(void) {
    printf("%d\n", acounter());
    return 0;
}