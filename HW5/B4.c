#include <stdio.h>
#include <stdlib.h> // для функции abs()

int main() {
    int number;
    scanf("%d", &number);

    if (number < 0) {
        number = abs(number);
    }

    if (number >= 100 && number <= 999) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
