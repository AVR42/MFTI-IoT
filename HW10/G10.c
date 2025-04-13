#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }

    char buffer[1001];
    fgets(buffer, sizeof(buffer), fin);
    fclose(fin);

    size_t len = strlen(buffer);
    while (len > 0 && (buffer[len-1] == '\n' || buffer[len-1] == '\r')) {
        buffer[len-1] = '\0';
        len--;
    }

    char *max_word = NULL;
    int max_len = 0;

    char *word = strtok(buffer, " ");
    while (word != NULL) {
        int current_len = strlen(word);
        if (current_len > max_len) {
            max_len = current_len;
            max_word = word;
        }
        word = strtok(NULL, " ");
    }

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }

    if (max_word != NULL) {
        fprintf(fout, "%s", max_word);
    }

    fclose(fout);
    return 0;
}
