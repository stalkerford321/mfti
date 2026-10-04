#include <stdio.h>

int grow_up(int n) {
    int prev = 10; 
    while (n > 0) {
        int d = n % 10;
        if (d >= prev) {
            return 0;
        }
        prev = d;
        n /= 10;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (grow_up(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}