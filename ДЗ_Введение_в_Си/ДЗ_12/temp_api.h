#ifndef TEMP_API_H
#define TEMP_API_H

#define MAX_RECORDS 10000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} temperature_record_t;

// Функции статистики
float get_monthly_avg_temp(temperature_record_t *data, int count, int year, int month);
int get_monthly_min_temp(temperature_record_t *data, int count, int year, int month);
int get_monthly_max_temp(temperature_record_t *data, int count, int year, int month);

float get_yearly_avg_temp(temperature_record_t *data, int count);
int get_yearly_min_temp(temperature_record_t *data, int count);
int get_yearly_max_temp(temperature_record_t *data, int count);

// Функции работы с массивом
void add_record(temperature_record_t *data, int *count, temperature_record_t record);
void remove_record(temperature_record_t *data, int *count, int index);
void sort_records_by_date(temperature_record_t *data, int count);
void print_records(temperature_record_t *data, int count);

// Функции файлов
int load_from_csv(const char *filename, temperature_record_t *data);
void print_help(void);

#endif // TEMP_API_H