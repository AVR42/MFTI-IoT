#ifndef TEMP_FUNCTIONS_H //include guard
#define TEMP_FUNCTIONS_H //

typedef struct {
    int year, month, day, hour, minute, temperature;
} Reading; // определение структуры Reading 

void print_help(); // вывести справку
int read_csv_file(const char *filename, Reading **readings); // чтение файла и запись
void print_month_stats(const Reading *readings, int count, int month); //вывести статистику по месяцу
void print_all_months_stats(const Reading *readings, int count); // вывести статистику по всем 12 месяцам каждый
void print_year_stats(const Reading *readings, int count); // вывести статистику по году

#endif
