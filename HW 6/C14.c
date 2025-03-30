#include <stdio.h>

int func(int n) {
	int sum = 0;
		for (; n > 0; n /= 10)
		sum += n % 10;
    return sum % 2 == 0;
}

int main() {
    int number;
		scanf("%d", &number);
		printf("%s", func(number)? "YES" : "NO");
				return 0;
}
