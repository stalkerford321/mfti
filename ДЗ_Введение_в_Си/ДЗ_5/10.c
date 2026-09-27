#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int prev = 10; 
    while (n > 0) {
        int d = n % 10;
        if (d >= prev) {
            printf("NO\n");
            return 0;
        }
        prev = d;
        n /= 10;
    }
    printf("YES\n");
    return 0;
}