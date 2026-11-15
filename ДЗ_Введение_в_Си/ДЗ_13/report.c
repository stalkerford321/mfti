#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"

#ifdef _WIN32
#include <getopt.h> 
#else
#include <unistd.h> 
#endif

// Выводит справку по использованию программы и списку доступных ключей
void print_help() {
    printf("Usage: report [options]\n");
    printf("Options:\n");
    printf("  -h            Show this help message\n");
    printf("  -f <file>     Input CSV file to process\n");
    printf("  -m <month>    Show statistics only for the specified month (1-12)\n");
}

// Главная функция программы: обрабатывает аргументы командной строки, загружает данные и выводит статистику
int main(int argc, char *argv[]) {
    TempNode *head = NULL;
    int show_month = 0;
    char *filename = NULL;

    if (argc == 1) {
        print_help();
        return 0;
    }

    int opt;
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
                if (show_month < 1 || show_month > 12) {
                    printf("Error: Month must be between 1 and 12.\n");
                    return 1;
                }
                break;
            case '?':
                printf("Error: Invalid argument. Use -h for help.\n");
                return 1;
        }
    }

    if (filename != NULL) {
        int loaded = load_from_csv(filename, &head);
        printf("Loaded %d valid records.\n\n", loaded);
        
        if (loaded > 0) {
            int year = head->year; 
            print_monthly_statistics(head, show_month, year);
            if (show_month == 0) {
                printf("\n");
                print_yearly_statistics(head);
            }
        } else {
            printf("No valid data loaded.\n");
        }
    } else {
        printf("Error: No input file specified. Use -h for help.\n");
    }

    free_list(head);
    return 0;
}