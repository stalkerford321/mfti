#include <stdio.h>

void reverse_string(void) {
    int c = getchar();
    if (c == '.' || c == EOF) {
        return;
    }
    reverse_string();   
    putchar(c);         
}

int main(void) {
    reverse_string();
    printf("\n");
    return 0;
}