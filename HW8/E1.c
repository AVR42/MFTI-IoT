#include <stdio.h>

int main()
{
    int arr[5];
    double sum = 0;

    scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

    for(int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    printf("%.3f", sum / 5);
    return 0;
}
