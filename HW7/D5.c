#include <stdio.h>

void print_num(int num)
{
		if (num>=2)
		{
			print_num( num / 2);
		}
		printf("%d", num % 2);

}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	print_num(N);
	return 0;
}
