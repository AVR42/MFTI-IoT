#include <stdio.h>

int main() {
    int arr[10];

    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 2; i++) {
        int temp = arr[i];
        arr[i] = arr[4-i];
        arr[4-i] = temp;
    }

      for(int i = 0; i < 2; i++) {
        int temp = arr[5+i];
        arr[5+i] = arr[9-i];
        arr[9-i] = temp;
    }

    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
