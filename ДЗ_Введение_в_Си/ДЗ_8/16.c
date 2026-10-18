#include <stdio.h>

int main(void) {
    int a[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    int best = a[0];
    int best_count = 0;

    for (int i = 0; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (a[j] == a[i]) {
                count++;
            }
        }
        if (count > best_count) {
            best_count = count;
            best = a[i];
        }
    }

    printf("%d\n", best);
    return 0;
}