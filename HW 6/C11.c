#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    int num1, num2;
     scanf("%d %d", &num1, &num2);

    printf("%d\n", gcd(num1, num2));

    return 0;
}
