#include <stdio.h>

int main() {
    int arr[12];

    for(int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 2; i++) {
        int temp = arr[i];
        arr[i] = arr[3-i];
        arr[3-i] = temp;
    }

    for(int i = 0; i < 2; i++) {
        int temp = arr[4+i];
        arr[4+i] = arr[7-i];
        arr[7-i] = temp;
    }

    for(int i = 0; i < 2; i++) {
        int temp = arr[8+i];
        arr[8+i] = arr[11-i];
        arr[11-i] = temp;
    }

    for(int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
