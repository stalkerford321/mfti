#include "temp_api.h"
#include <stddef.h>

float get_monthly_avg_temp(temperature_record_t *data, int count, int year, int month) {
    (void)data; (void)count; (void)year; (void)month;
    return 15.5f; // Заглушка: средняя температура
}

int get_monthly_min_temp(temperature_record_t *data, int count, int year, int month) {
    (void)data; (void)count; (void)year; (void)month;
    return -5; // Заглушка: минимум
}

int get_monthly_max_temp(temperature_record_t *data, int count, int year, int month) {
    (void)data; (void)count; (void)year; (void)month;
    return 25; // Заглушка: максимум
}

float get_yearly_avg_temp(temperature_record_t *data, int count) {
    (void)data; (void)count;
    return 12.3f; // Заглушка: среднегодовая
}

int get_yearly_min_temp(temperature_record_t *data, int count) {
    (void)data; (void)count;
    return -10; // Заглушка: годовой минимум
}

int get_yearly_max_temp(temperature_record_t *data, int count) {
    (void)data; (void)count;
    return 30; // Заглушка: годовой максимум
}