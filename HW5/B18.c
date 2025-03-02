#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 0) {
        printf("n>2!.\n");
        return 1;
    }

    int a = 1, b = 1;

    for (int i = 0; i < n; i++) {
        printf("%d ", a);

        int next = a + b;
        a = b;
        b = next;
    }

    printf("\n");

    return 0;
}
