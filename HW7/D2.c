#include <stdio.h>

int sum_numbers(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum_numbers(n - 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", sum_numbers(N));
    return 0;
}

