#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Добавляет новую запись о температуре в конец связного списка
void add_record(TempNode **head, TempNode **tail, int year, int month, int day, int hour, int minute, int temperature) {
    TempNode *new_node = (TempNode *)malloc(sizeof(TempNode));
    if (!new_node) return;
    
    new_node->year = year;
    new_node->month = month;
    new_node->day = day;
    new_node->hour = hour;
    new_node->minute = minute;
    new_node->temperature = temperature;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

// Освобождает всю выделенную память для связного списка
void free_list(TempNode *head) {
    TempNode *current = head;
    while (current != NULL) {
        TempNode *temp = current;
        current = current->next;
        free(temp);
    }
}

// Читает CSV-файл, проверяет данные на корректность и заполняет список, возвращает количество успешных записей
int load_from_csv(const char *filename, TempNode **head) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }

    char line[256];
    int line_num = 0;
    int valid_count = 0;
    TempNode *tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        line_num++;
        line[strcspn(line, "\r\n")] = 0;

        if (strlen(line) == 0) continue;

        if (line_num == 1 && (line[0] < '0' || line[0] > '9')) continue;

        int y, m, d, h, min, t;
        int parsed = sscanf(line, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &min, &t);

        if (parsed != 6 || m < 1 || m > 12 || d < 1 || d > 31 || h < 0 || h > 23 || min < 0 || min > 59 || t < -99 || t > 99) {
            printf("Error: Invalid format in line %d: %s\n", line_num, line);
            continue;
        }

        add_record(head, &tail, y, m, d, h, min, t);
        valid_count++;
    }
    
    fclose(file);
    return valid_count;
}

// Выводит таблицу со статистикой (среднее, максимум, минимум) по месяцам (или за один конкретный месяц)
void print_monthly_statistics(TempNode *head, int target_month, int year) {
    printf("# Year Month NuValue ErValue MonthAvg MonthMax MonthMin\n");
    
    int start_m = (target_month != 0) ? target_month : 1;
    int end_m = (target_month != 0) ? target_month : 12;

    for (int m = start_m; m <= end_m; m++) {
        int count = 0;
        int sum = 0;
        int min = INT_MAX;
        int max = INT_MIN;

        TempNode *curr = head;
        while (curr != NULL) {
            if (curr->month == m && curr->year == year) {
                sum += curr->temperature;
                if (curr->temperature < min) min = curr->temperature;
                if (curr->temperature > max) max = curr->temperature;
                count++;
            }
            curr = curr->next;
        }

        if (count > 0) {
            printf("  %d    %2d     %4d      %d    %6.1f     %4d     %4d\n", 
                   year, m, count, 0, (float)sum / count, max, min);
        }
    }
}

// Выводит общую статистику за весь год
void print_yearly_statistics(TempNode *head) {
    if (head == NULL) {
        printf("No data available.\n");
        return;
    }

    int count = 0;
    int sum = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    TempNode *curr = head;
    while (curr != NULL) {
        sum += curr->temperature;
        if (curr->temperature < min) min = curr->temperature;
        if (curr->temperature > max) max = curr->temperature;
        count++;
        curr = curr->next;
    }

    printf("Year statistic: average is %.2f, max is %d, min is %d\n", 
           (float)sum / count, max, min);
}