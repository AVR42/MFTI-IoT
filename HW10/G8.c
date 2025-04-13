#include <stdio.h>

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }

    char str[1002];
    fgets(str, sizeof(str), fin);
    fclose(fin);

    int numbers[500];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_digit(str[i])) {
            int num = 0;
            while (is_digit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            numbers[count++] = num;
            i--;
        }
    }

    bubble_sort(numbers, count);

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }

    if (count > 0) {
        fprintf(fout, "%d", numbers[0]);
        for (int i = 1; i < count; i++) {
            fprintf(fout, " %d", numbers[i]);
        }
    }

    fclose(fout);
    return 0;
}
