
#include <stdio.h>


int main(void) {
    int num1, num2, num3, N;
        scanf("%d %d %d", &num1, &num2, &num3);
        if (num1 > num2 )
        {
			if (num1 > num3) N=num1;
			else N=num3;
		}

        else
        {
			if( num2 > num3) N=num2;
			else N=num3;
		}
			printf("%d\n", N);
    return 0;
}
