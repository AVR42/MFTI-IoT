#include <stdio.h>
#include <limits.h>

int main(void)
{
	int number;
	int min=INT_MAX;

	for (int i=0; i < 5;i++) {
		scanf("%d", &number);
		if (min > number) min = number;
	}
	printf("%d", min);
    return 0;
}
