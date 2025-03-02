#include <stdio.h>

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    if (num1 > num2) {
        printf("Above\n");
    } else if (num1 < num2) {
        printf("Less\n");
    } else {
        printf("Equal\n");
    }

    return 0;
}
