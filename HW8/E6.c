#include <stdio.h>

int main() {
    int arr[12];
    float sum=0;

    for(int i = 0; i < 12; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

   // printf("%d %d %d %d %d %d %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10], arr[11]);
   printf("%.2f", sum/12);
	return 0;
}
