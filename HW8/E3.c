#include <stdio.h>

int main() {
    int num, max, min, max_i = 0, min_i = 0;

    scanf("%d", &num);
    max = min = num;

    for (int i = 1; i < 10; i++) {
        scanf("%d", &num);
        if (num > max) {
            max = num;
            max_i = i;
        }
        if (num < min) {
            min = num;
            min_i = i;
        }
    }

    printf("%d %d %d %d", max_i + 1, max, min_i + 1, min);
    return 0;
}
