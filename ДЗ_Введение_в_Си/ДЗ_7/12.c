#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int first = 1;
    int count = 0;
    for (int k = 1; count < n; k++) {
        for (int i = 0; i < k && count < n; i++) {
            if (!first) {
                printf(" ");
            }
            printf("%d", k);
            first = 0;
            count++;
        }
    }
    printf("\n");
    return 0;
}