#include <stdio.h>

int main() {
    int input[10];
    int output[10];
    int count = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
    }

    for (int i = 0; i < 10; i++) {
        int num = input[i];
        int tens = (num / 10) % 10;
        if (tens == 0) {
            output[count] = num;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}
