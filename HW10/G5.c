#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }

    char str[1002];
    fgets(str, sizeof(str), fin);
    fclose(fin);

    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
            case 'a': str[i] = 'b'; break;
            case 'A': str[i] = 'B'; break;
            case 'b': str[i] = 'a'; break;
            case 'B': str[i] = 'A'; break;
        }
    }

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }
    fprintf(fout, "%s", str);
    fclose(fout);

    return 0;
}
