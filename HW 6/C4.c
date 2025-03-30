#include <stdio.h>

int func(int x)
{
	int result = 0;
		if ((x >= -2) && (x < 2))
			result = x * x;
		else if (x >= 2)
			result = x*x+4*x+5;
		else if (x < -2)
			result = 4;
		return result;
}

int main(void)
{
	int a=1, b, max = 0;
		while (a != 0)
		{
			scanf("%d", &a);
			b = func(a);
			if (b > max)
				max = b;
		}
    printf("%d ", max);
    return 0;
}
