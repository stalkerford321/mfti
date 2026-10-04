#include <stdio.h>

int to_base(int n, int p) {
    if (n == 0) return 0;
    int result = 0;   
    int mult = 1;     
    while (n > 0) {
        int digit = n % p;          
        result += digit * mult;     
        mult *= 10;                 
        n /= p;                    
    }
    return result;
}

int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d\n", to_base(n, p));
    return 0;
}