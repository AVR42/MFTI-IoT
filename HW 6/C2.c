#include <stdio.h>

int stepen(int n, int p)
{
	int result = 1;
		for (int i = 1; i <= p; i++)
			result *= n;
		return result;
}

int main()
{
	int x=1, y=1;
			scanf("%d %d", &x, &y);
		printf("%d", stepen(x, y));
		return 0;
}
