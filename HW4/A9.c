
#include <stdio.h>

int main(void)
{
	int number;
	int max=0;

	for (int i=0; i < 5;i++) {
		scanf("%d", &number);
		if (max < number) max = number;
	}
	printf("%d", max);
    return 0;
}
