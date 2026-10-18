#include <stdio.h>
#include <string.h>

int main(void) {
    char s[100];
    scanf("%s", s);

    int cnt[10] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        cnt[s[i] - '0']++;
    }

    for (int d = 9; d >= 0; d--) {
        for (int k = 0; k < cnt[d]; k++) {
            printf("%d", d);
        }
    }
    printf("\n");

    return 0;
}