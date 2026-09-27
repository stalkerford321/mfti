#include <stdio.h>

int main(void) {
    int n, even = 0, odd = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("1 0\n");
        return 0;
    }
    while (n > 0) {
        int d = n % 10;
        if (d % 2 == 0)
            even++;
        else
            odd++;
        n /= 10;
    }
    printf("%d %d\n", even, odd);
    return 0;
}