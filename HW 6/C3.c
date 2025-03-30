#include <stdio.h>

int middle(int a, int b)
{
	int result = 1;
		result=(a+b)/2;
		return result;
}

int main()
{
	int x=1, y=1;
			scanf("%d %d", &x, &y);
		printf("%d", middle(x, y));
		return 0;
}

