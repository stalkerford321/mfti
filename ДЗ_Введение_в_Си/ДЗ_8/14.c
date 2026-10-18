#include <stdio.h>

int main(void) {
    int a[10];
    int b[10];      // результирующий массив
    int n = 0;      // количество элементов в b

    // считываем исходный массив
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++) {
        // считаем, сколько раз a[i] встречается в массиве
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (a[j] == a[i]) {
                count++;
            }
        }

        // встречается больше одного раза?
        if (count > 1) {
            // проверяем, нет ли уже такого числа в результате
            int already = 0;
            for (int k = 0; k < n; k++) {
                if (b[k] == a[i]) {
                    already = 1;
                    break;
                }
            }

            if (!already) {
                b[n] = a[i];
                n++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}