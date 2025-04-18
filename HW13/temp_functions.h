#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

typedef struct {
    int year, month, day, hour, minute, temperature;
} Reading;

void print_help();
int read_csv_file(const char *filename, Reading **readings);
void print_month_stats(const Reading *readings, int count, int month);
void print_all_months_stats(const Reading *readings, int count);
void print_year_stats(const Reading *readings, int count);

#endif
