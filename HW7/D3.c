#include <stdio.h>

void print_digits_reverse(int n) {
    if (n < 10) {
        printf("%d", n);
    } else {
        printf("%d ", n % 10);
        print_digits_reverse(n / 10);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    print_digits_reverse(N);
    return 0;
}
