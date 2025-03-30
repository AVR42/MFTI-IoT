#include <stdio.h>

void print_num(int num)
{
		if (num>=10)
		{
			print_num( num / 10);
		}
		printf("%d ", num % 10);

}

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	print_num(N);
	return 0;
}
