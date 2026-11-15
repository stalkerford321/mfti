#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// --- Статистика ---
float get_monthly_avg_temp(temperature_record_t *data, int count, int year, int month) {
    float sum = 0.0f; int found = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            sum += data[i].temperature; found++;
        }
    }
    return found ? (sum / found) : 0.0f;
}

int get_monthly_min_temp(temperature_record_t *data, int count, int year, int month) {
    int min = INT_MAX; int found = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            if (data[i].temperature < min) min = data[i].temperature;
            found++;
        }
    }
    return found ? min : 0;
}

int get_monthly_max_temp(temperature_record_t *data, int count, int year, int month) {
    int max = INT_MIN; int found = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            if (data[i].temperature > max) max = data[i].temperature;
            found++;
        }
    }
    return found ? max : 0;
}

float get_yearly_avg_temp(temperature_record_t *data, int count) {
    if (count == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count; i++) sum += data[i].temperature;
    return sum / count;
}

int get_yearly_min_temp(temperature_record_t *data, int count) {
    if (count == 0) return 0;
    int min = INT_MAX;
    for (int i = 0; i < count; i++) if (data[i].temperature < min) min = data[i].temperature;
    return min;
}

int get_yearly_max_temp(temperature_record_t *data, int count) {
    if (count == 0) return 0;
    int max = INT_MIN;
    for (int i = 0; i < count; i++) if (data[i].temperature > max) max = data[i].temperature;
    return max;
}

// --- Работа с массивом ---
void add_record(temperature_record_t *data, int *count, temperature_record_t record) {
    if (*count < MAX_RECORDS) {
        data[*count] = record;
        (*count)++;
    }
}

void remove_record(temperature_record_t *data, int *count, int index) {
    if (index >= 0 && index < *count) {
        for (int i = index; i < *count - 1; i++) {
            data[i] = data[i + 1];
        }
        (*count)--;
    }
}

void sort_records_by_date(temperature_record_t *data, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int y1 = data[j].year, y2 = data[j+1].year;
            int m1 = data[j].month, m2 = data[j+1].month;
            int d1 = data[j].day, d2 = data[j+1].day;
            if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2)) {
                temperature_record_t temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void print_records(temperature_record_t *data, int count) {
    for (int i = 0; i < count; i++) {
        printf("%04d-%02d-%02d %02d:%02d T=%d\n", 
               data[i].year, data[i].month, data[i].day, 
               data[i].hour, data[i].minute, data[i].temperature);
    }
}

// --- Работа с файлами ---
int load_from_csv(const char *filename, temperature_record_t *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }
    
    char line[256];
    int count = 0;
    
    while (fgets(line, sizeof(line), file) && count < MAX_RECORDS) {
        // Пропускаем возможный заголовок или пустые строки
        if (line[0] == 'y' || line[0] == 'Y' || line[0] == '\n') continue;
        
        int y, m, d, h, min, t;
        // Ожидаемый формат в CSV: year,month,day,hour,minute,temperature
        if (sscanf(line, "%d,%d,%d,%d,%d,%d", &y, &m, &d, &h, &min, &t) == 6) {
            data[count].year = y;
            data[count].month = m;
            data[count].day = d;
            data[count].hour = h;
            data[count].minute = min;
            data[count].temperature = t;
            count++;
        }
    }
    fclose(file);
    return count;
}

void print_help(void) {
    printf("Usage: temp_app [options]\n");
    printf("Options:\n");
    printf("  -h            Show this help message\n");
    printf("  -f <file>     Read data from specified CSV file\n");
    printf("  -m <month>    Show statistics for the specified month (1-12)\n");
}