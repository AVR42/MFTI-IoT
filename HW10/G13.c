#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Error opening input file\n");
        return 1;
    }

    char path[1001];
    fgets(path, sizeof(path), fin);
    fclose(fin);

    size_t len = strlen(path);
    while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == '\r')) {
        path[len - 1] = '\0';
        len--;
    }

    char *last_slash = strrchr(path, '/');
    char *filename = (last_slash != NULL) ? last_slash + 1 : path;
    char *last_dot = strrchr(filename, '.');

    if (last_dot != NULL) {
        *last_dot = '\0';
    }

    strcat(path, ".html");

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Error opening output file\n");
        return 1;
    }

    fprintf(fout, "%s", path);
    fclose(fout);

    return 0;
}
