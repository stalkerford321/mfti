#include <stdio.h>

int main(void) {
    int a[12];
    int sum = 0;

    for (int i = 0; i < 12; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    double avg = sum / 12.0;
    printf("%.2f\n", avg);

    return 0;
}