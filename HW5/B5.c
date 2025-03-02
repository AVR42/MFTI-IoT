#include <stdio.h>
#include <stdlib.h> // для функции abs()

int main() {
    int number, sum = 0;

    scanf("%d", &number);

    number = abs(number);

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    printf("%d\n", sum);

    return 0;
}
