#include <stdio.h>

int main() {
    int a[10];

    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    int max1 = a[0], max2 = a[1];
    if(max2 > max1) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for(int i = 2; i < 10; i++) {
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2) {
            max2 = a[i];
        }
    }

    printf("%d", max1 + max2);
    return 0;
}
