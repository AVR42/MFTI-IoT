#include <stdio.h>

int main() {
    char input[105] = {0}; // Буфер для ввода (100 символов + переносы + нуль)
    char output[350] = {0}; // Буфер для вывода (3*100 + разделители + число)

    // Чтение из файла
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }
    fgets(input, sizeof(input), fin);
    fclose(fin);

    // Удаление незначащих переносов в конце
    int len = 0;
    while (input[len] != '\0') len++; // Подсчет длины
    while (len > 0 && (input[len - 1] == '\n' || input[len - 1] == '\r')) {
        input[len - 1] = '\0'; // Обрезаем символ
        len--; // Корректируем длину
    }

    // Формирование результата
    int str_length = len; // Актуальная длина строки
    snprintf(output, sizeof(output), "%s, %s, %s %d", input, input, input, str_length);

    // Запись в файл
    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }
    fprintf(fout, "%s", output);
    fclose(fout);

    return 0;
}
