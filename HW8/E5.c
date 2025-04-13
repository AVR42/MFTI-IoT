#include <stdio.h>

int main() {
    int arr[10];
    int p=0;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > 0)
        {
        p = arr[i] + p;
		}

    }

    printf("%d", p);
    return 0;
}
