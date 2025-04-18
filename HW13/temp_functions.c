#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"

void print_help() {
    printf("Использование:\n");
    printf("  -h                 Показать справку\n");
    printf("  -f <file.csv>      Указать CSV-файл\n");
    printf("  -m <месяц 1-12>    Показать статистику за конкретный месяц\n");
}

int read_csv_file(const char *filename, Reading **readings) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    int capacity = 10000, count = 0;
    *readings = malloc(capacity * sizeof(Reading));
    if (!*readings) return 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Reading r;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &r.year, &r.month, &r.day, &r.hour, &r.minute, &r.temperature) == 6) {
            if (count >= capacity) {
                capacity *= 2;
                *readings = realloc(*readings, capacity * sizeof(Reading));
                if (!*readings) break;
            }
            (*readings)[count++] = r;
        }
    }

    fclose(file);
    return count;
}

void print_month_stats(const Reading *readings, int count, int month) {
    int min = 1000, max = -1000, sum = 0, total = 0;

    for (int i = 0; i < count; i++) {
        if (readings[i].month == month) {
            int temp = readings[i].temperature;
            if (temp < min) min = temp;
            if (temp > max) max = temp;
            sum += temp;
            total++;
        }
    }

    if (total == 0) {
        printf("Нет данных для месяца %d\n", month);
        return;
    }

    printf("\nМесяц %d:\n", month);
    printf("  Средняя температура: %.2f\n", sum / (float)total);
    printf("  Минимум: %d\n", min);
    printf("  Максимум: %d\n", max);
}

void print_all_months_stats(const Reading *readings, int count) {
    for (int m = 1; m <= 12; m++) {
        print_month_stats(readings, count, m);
    }
}

void print_year_stats(const Reading *readings, int count) {
    int sum = 0, min = 1000, max = -1000;

    for (int i = 0; i < count; i++) {
        int t = readings[i].temperature;
        sum += t;
        if (t < min) min = t;
        if (t > max) max = t;
    }

    printf("\nГодовая статистика:\n");
    printf("  Средняя температура: %.2f\n", sum / (float)count);
    printf("  Минимум: %d\n", min);
    printf("  Максимум: %d\n", max);
}
