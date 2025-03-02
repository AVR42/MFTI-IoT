#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Error\n");
        return 1;
            }

     for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    }

    return 0;
}
