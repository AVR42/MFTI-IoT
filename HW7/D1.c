#include <stdio.h>

void print_numbers(int n) {
    if (n > 1)
    {
        print_numbers(n - 1);
    }
    printf("%d ", n);
}

int main() {
    int N;
    scanf("%d", &N);
    print_numbers(N);
    return 0;
}
