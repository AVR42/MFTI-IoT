
#include <stdio.h>


int main() {
    int num1, ed, des, sot, N;

        scanf("%d", &num1);
        ed = (num1/100) %10;
        des =(num1/10) % 10;
        sot = num1 % 10;
			if (sot > des )
			{
				if (sot > ed) N=sot;
				else N=ed;
			}

			else
			{
				if( des > ed) N=des;
				else N=ed;
			}
		printf("%d", N);
      return 0;
}
