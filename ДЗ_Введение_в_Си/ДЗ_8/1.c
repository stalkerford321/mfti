#include <stdio.h>

int main(void) {
    int a[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    double avg = sum / 5.0;
    printf("%.3f\n", avg);

    return 0;
}