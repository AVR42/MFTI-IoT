#include <stdio.h>

int func(int n)
{
	int result=0;
		for (int i=1; i<=n; i++)
			result +=i;
	return result;
}

int main(void)
{
	int a;
		scanf("%d", &a);
		printf("%d ", func(a));
		return 0;
}

