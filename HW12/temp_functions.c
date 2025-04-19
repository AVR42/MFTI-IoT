#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"

void print_help() {
    printf("Использование:\n");
    printf("  -h                 Показать справку\n");
    printf("  -f <file.csv>      Указать CSV-файл\n");
    printf("  -m <месяц 1-12>    Показать статистику за конкретный месяц\n");
} // вывод Справки

int read_csv_file(const char *filename, Reading **readings) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0; // открываем файл и проверяем на наличие файла

    int capacity = 10000, count = 0;
    *readings = malloc(capacity * sizeof(Reading)); //выделяем память под массив 
    if (!*readings) return -1; // и проверяем на выделение памяти, -1 что бы отличать

    char line[256]; // 256 символов в строке
    while (fgets(line, sizeof(line), file)) { // читаем строку
        Reading r;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &r.year, &r.month, &r.day, &r.hour, &r.minute, &r.temperature) == 6) { // извлекаем 6 чисел и проверяем на заполнение
            if (count >= capacity) { //если счет больше объема
                capacity *= 2; // удваиваем емкость
                *readings = realloc(*readings, capacity * sizeof(Reading)); //перезаписываем
                if (!*readings) break; // проверяем, прерываем
            } // проверка на переполнение и увеличение памяти
            (*readings)[count++] = r; // сохраняем в массив, увеличиваем счет.
        }
    }

    fclose(file);
    return count;
}

void print_month_stats(const Reading *readings, int count, int month) { //ЧИТАЕМ массив
    int min = 1000, max = -1000, sum = 0, total = 0; // min и max заведомо завысили

    for (int i = 0; i < count; i++) {
        if (readings[i].month == month) { //читаем только интересующий нас месяц
            int temp = readings[i].temperature; //читаем температуру
            if (temp < min) min = temp; //если t меньше min, то это новый минимум
            if (temp > max) max = temp; //если t больше max, то это новый максимум
            sum += temp; //складываем все температуры для средней в месяц
            total++; 
        }
    }

    if (total == 0) { 
        printf("Нет данных для месяца %d\n", month);
        return; // если нет данных. нет данных
    }

    printf("\nМесяц %d:\n", month); 
    printf("  Средняя температура: %.2f\n", sum / (float)total); // общая сумма температур / количество считываний
    printf("  Минимум: %d\n", min);
    printf("  Максимум: %d\n", max);
}

void print_all_months_stats(const Reading *readings, int count) {
    for (int m = 1; m <= 12; m++) { // 
        print_month_stats(readings, count, m); //вызов функции по месяцам
    }
}

void print_year_stats(const Reading *readings, int count) {
    int sum = 0, min = 1000, max = -1000;

    for (int i = 0; i < count; i++) {
        int t = readings[i].temperature;
        sum += t; //складываем все температуры для средней в месяц
        if (t < min) min = t; //если t меньше min, то это новый минимум
        if (t > max) max = t; //если t больше max, то это новый максимум
    }

    printf("\nГодовая статистика:\n");
    printf("  Средняя температура: %.2f\n", sum / (float)count);
    printf("  Минимум: %d\n", min);
    printf("  Максимум: %d\n", max);
}
