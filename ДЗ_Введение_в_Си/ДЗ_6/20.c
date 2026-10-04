#include <stdio.h>

int main(void) {
    int c;
    int depth = 0;   
    int ok = 1;      
    while ((c = getchar()) != '.' && c != EOF) {
        if (c == '(') {
            depth++;
        } else if (c == ')') {
            depth--;
            if (depth < 0) {
                ok = 0;   
            }
        }
    }
    if (ok && depth == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}