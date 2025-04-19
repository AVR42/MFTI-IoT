#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

int main(int argc, char *argv[]) {
    
    char *filename = NULL;
    int month = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            filename = argv[++i];
            // printf("Файл для обработки: %s\n", filename); // Отладочное сообщение
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            month = atoi(argv[++i]);
            // printf("Запрашиваемая статистика за месяц: %d\n", month); // Отладочное сообщение
        }
    }

    if (!filename) {
        fprintf(stderr, "Ошибка: не указан файл с данными. Используй -f <filename.csv>\n");
        return 1;
    }

    // Чтение CSV файла
    Reading *readings = NULL;
    int count = read_csv_file(filename, &readings);
    // printf("Чтение завершено. Всего записей: %d\n", count); // Отладочное сообщение

    if (count <= 0) {
        fprintf(stderr, "Не удалось считать данные из файла.\n");
        return 1;
    }
    
    if (month > 0 && month <= 12) { // Если был задан месяц
        print_month_stats(readings, count, month);
    } else {
        print_all_months_stats(readings, count); // Статистика по всем месяцам
        print_year_stats(readings, count); // Годовая статистика
    }

    free(readings);

    return 0;
}
