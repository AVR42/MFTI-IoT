#include <stdio.h>
#include <limits.h>

int main(void)
{
	int number;
	int min=INT_MAX;
	int max=INT_MIN;
	int Sum;

		for (int i=0; i < 5;i++) {
			scanf("%d", &number);
			if (min > number) min = number;
			if (max < number) max = number;
		}
		Sum = min + max;
		printf("%d", Sum);
    return 0;
}
