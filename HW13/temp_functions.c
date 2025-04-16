#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

void print_help() {
    printf("Использование:\n");
    printf("  -h                  Показать это сообщение\n");
    printf("  -f <file.csv>       Указать CSV файл\n");
    printf("  -m <номер месяца>   Показать статистику только для указанного месяца\n");
}

int read_csv(const char *filename, Reading *readings) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Не удалось открыть файл");
        return -1;
    }

    char line[256];
    int count = 0, line_num = 0;

    // Чтение файла построчно
    while (fgets(line, sizeof(line), file)) {
        ++line_num;
        // Пропускаем строку заголовков
        if (line_num == 1 && strstr(line, "YEAR")) continue;

        Reading r;
        // Разбираем строку CSV
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &r.year, &r.month, &r.day, &r.hour, &r.minute, &r.temperature) != 6) {
            fprintf(stderr, "Ошибка в строке %d: %s", line_num, line);
            continue; // Пропускаем ошибочную строку
        }

        // Проверка на корректность температуры
        if (r.temperature < -99 || r.temperature > 99) {
            fprintf(stderr, "Ошибка в температуре в строке %d: %s", line_num, line);
            continue; // Пропускаем строку с ошибочной температурой
        }

        readings[count++] = r; // Сохраняем данные в массив
    }

    fclose(file);
    printf("Чтение завершено, обработано %d строк.\n", count); // Отладочное сообщение
    return count;
}

void print_month_stats(const Reading *readings, int count, int month) {
    int min = 100, max = -100, sum = 0, total = 0;

    printf("Обрабатываю данные для месяца: %d\n", month); // Отладочное сообщение

    // Обработка только строк с данным месяцем
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

    printf("Месяц %d:\n", month);
    printf("  Средняя температура: %.2f\n", sum / (float)total);
    printf("  Мин. температура: %d\n", min);
    printf("  Макс. температура: %d\n", max);
}

void print_all_months_stats(const Reading *readings, int count) {
    printf("Обрабатываю данные по всем месяцам...\n"); // Отладочное сообщение
    for (int m = 1; m <= 12; m++) {
        print_month_stats(readings, count, m);
    }
}

void print_year_stats(const Reading *readings, int count) {
    int min = 100, max = -100, sum = 0;

    printf("Обрабатываю данные за год...\n"); // Отладочное сообщение

    for (int i = 0; i < count; i++) {
        int temp = readings[i].temperature;
        if (temp < min) min = temp;
        if (temp > max) max = temp;
        sum += temp;
    }

    if (count == 0) {
        printf("Нет данных для расчета статистики по году.\n");
        return;
    }

    printf("\nГодовая статистика:\n");
    printf("  Средняя температура: %.2f\n", sum / (float)count);
    printf("  Мин. температура: %d\n", min);
    printf("  Макс. температура: %d\n", max);
}
