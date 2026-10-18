#include <stdio.h>
#include <string.h>

void print_digit_counts(const char *number) {
    int counts[10] = {0};
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        int digit = number[i] - '0';
        counts[digit]++;
    }

    for (int digit = 0; digit <= 9; digit++) {
        if (counts[digit] > 0) {
            printf("%d %d\n", digit, counts[digit]);
        }
    }
}

int main(void) {
    char number[1001];
    scanf("%1000s", number);

    print_digit_counts(number);

    return 0;
}