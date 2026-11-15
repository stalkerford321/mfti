#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

#ifdef _WIN32
#include <getopt.h> 
#else
#include <unistd.h> 
#endif

int main(int argc, char *argv[]) {
    temperature_record_t data[MAX_RECORDS];
    int count = 0;
    int show_month = 0;
    char *filename = NULL;

    int opt;
    // Обработка аргументов: h - помощь, f: - файл, m: - месяц
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                show_month = atoi(optarg);
                break;
            case '?':
                printf("Error: Invalid argument. Use -h for help.\n");
                return 1;
        }
    }

    if (filename != NULL) {
        count = load_from_csv(filename, data);
        printf("Loaded %d records from %s\n\n", count, filename);
        // Для наглядности отсортируем данные по дате
        sort_records_by_date(data, count); 
    } else {
        printf("No input file provided. Creating test data...\n\n");
        // Если файл не задан, создадим тестовые записи через функцию добавления
        add_record(data, &count, (temperature_record_t){2026, 11, 15, 12, 30, 15});
        add_record(data, &count, (temperature_record_t){2026, 11, 15, 14, 0, 18});
        add_record(data, &count, (temperature_record_t){2026, 10, 10, 9, 15, 5});
    }

    if (count > 0) {
        if (show_month >= 1 && show_month <= 12) {
            // Вывод статистики только за указанный месяц (берем год из первой записи)
            int year = data[0].year; 
            printf("--- Statistics for %02d.%04d ---\n", show_month, year);
            printf("Average temp: %.2f\n", get_monthly_avg_temp(data, count, year, show_month));
            printf("Min temp: %d\n", get_monthly_min_temp(data, count, year, show_month));
            printf("Max temp: %d\n", get_monthly_max_temp(data, count, year, show_month));
        } else {
            // Вывод полной статистики за год
            printf("--- Yearly statistics ---\n");
            printf("Average yearly temp: %.2f\n", get_yearly_avg_temp(data, count));
            printf("Min yearly temp: %d\n", get_yearly_min_temp(data, count));
            printf("Max yearly temp: %d\n", get_yearly_max_temp(data, count));
            
            printf("\n--- All records ---\n");
            print_records(data, count);
        }
    } else {
        printf("No data to display.\n");
    }

    return 0;
}