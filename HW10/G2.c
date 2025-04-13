#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }

    int N;
    fscanf(fin, "%d", &N);
    fclose(fin);

    char result[N + 1]; // +1 для терминатора
    memset(result, 0, sizeof(result)); // Инициализируем массив нулями

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Нечетные позиции (0, 2, 4...) - буквы A, B, C...
            result[i] = 'A' + (i / 2);
        } else {
            // Четные позиции (1, 3, 5...) - цифры 2, 4, 6, 8, повторяющиеся
            result[i] = '2' + 2 * ((i / 2) % 4);
        }
    }

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }
    fprintf(fout, "%s", result);
    fclose(fout);

    return 0;
}
