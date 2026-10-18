#include <stdio.h>

int main(void)
{
    int x;
    int first = 1;
    int min = 0;
    int max = 0;
    long long sum = 0;

    while (scanf("%d", &x) == 1 && x != 0) {
        if (first) {
            min = x;
            max = x;
            first = 0;
        } else {
            if (x < min) min = x;
            if (x > max) max = x;
        }
        sum += x;
    }

    long long expected_sum = (long long)(min + max) * (max - min + 1) / 2;

    printf("%lld\n", expected_sum - sum);

    return 0;
}