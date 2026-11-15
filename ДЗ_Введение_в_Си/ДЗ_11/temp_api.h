#ifndef TEMP_API_H
#define TEMP_API_H

// Структура для хранения данных о температуре
typedef struct {
    int year;        // год (4 цифры)
    int month;       // месяц (2 цифры)
    int day;         // день (2 цифры)
    int hour;        // часы (2 цифры)
    int minute;      // минуты (2 цифры)
    int temperature; // температура (от -99 до 99)
} temperature_record_t;

// Прототипы функций статистики по месяцам
float get_monthly_avg_temp(temperature_record_t *data, int count, int year, int month);
int get_monthly_min_temp(temperature_record_t *data, int count, int year, int month);
int get_monthly_max_temp(temperature_record_t *data, int count, int year, int month);

// Прототипы функций статистики за год
float get_yearly_avg_temp(temperature_record_t *data, int count);
int get_yearly_min_temp(temperature_record_t *data, int count);
int get_yearly_max_temp(temperature_record_t *data, int count);

#endif // TEMP_API_H