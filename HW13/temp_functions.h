#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#define MAX_READINGS 100000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} Reading;

void print_help();
int read_csv(const char *filename, Reading *readings);
void print_month_stats(const Reading *readings, int count, int month);
void print_all_months_stats(const Reading *readings, int count);
void print_year_stats(const Reading *readings, int count);

#endif
