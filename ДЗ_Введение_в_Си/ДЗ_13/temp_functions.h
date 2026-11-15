#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

typedef struct TempNode {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
    struct TempNode *next;
} TempNode;

// Добавляет новую запись о температуре в конец связного списка
void add_record(TempNode **head, TempNode **tail, int year, int month, int day, int hour, int minute, int temperature);

// Освобождает всю выделенную память для связного списка
void free_list(TempNode *head);

// Читает CSV-файл, проверяет данные на корректность и заполняет список, возвращает количество успешных записей
int load_from_csv(const char *filename, TempNode **head);

// Выводит таблицу со статистикой (среднее, максимум, минимум) по месяцам (или за один конкретный месяц)
void print_monthly_statistics(TempNode *head, int target_month, int year);

// Выводит общую статистику за весь год
void print_yearly_statistics(TempNode *head);

#endif // TEMP_FUNCTIONS_H