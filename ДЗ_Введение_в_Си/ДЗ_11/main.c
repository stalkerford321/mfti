#include <stdio.h>
#include "temp_api.h"

int main(void) {
    temperature_record_t records[3] = {
        {2026, 11, 15, 12, 30, 15}, 
        {2026, 11, 15, 14, 0, 18},
        {2026, 11, 15, 9, 15, 5}   
    };
    int count = sizeof(records) / sizeof(records[0]);

    printf("--- Monthly statistics ---\n");
    printf("Average temp for 11.2026: %.2f\n", get_monthly_avg_temp(records, count, 2026, 11));
    printf("Min temp for 11.2026: %d\n", get_monthly_min_temp(records, count, 2026, 11));
    printf("Max temp for 11.2026: %d\n", get_monthly_max_temp(records, count, 2026, 11));

    printf("\n--- Yearly statistics ---\n");
    printf("Average yearly temp: %.2f\n", get_yearly_avg_temp(records, count));
    printf("Min yearly temp: %d\n", get_yearly_min_temp(records, count));
    printf("Max yearly temp: %d\n", get_yearly_max_temp(records, count));

    printf("\nExample of formatted date output:\n");
    printf("%02d.%02d.%04d %02d:%02d, T=%d\n",
           records[2].day, records[2].month, records[2].year,
           records[2].hour, records[2].minute, records[2].temperature);

    return 0;
}