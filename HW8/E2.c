#include <stdio.h>

int main()
{
    int arr[5];
      scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

	int min = arr[0];
	for(int i = 1; i < 5; i++)
	{
        if(arr[i] < min)
		{
            min = arr[i];
		}
	}

	printf("%d", min);
    return 0;
}
