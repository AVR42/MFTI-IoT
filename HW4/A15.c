
#include <stdio.h>

int main() {
    double x1, y1, x2, y2;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    if (x1 == x2 && y1 == y2) {
        printf("Error\n");
        return 1;
    }

    if (x1 == x2) {
        printf("x = %.2lf\n", x1);
        return 0;
    }

    double k = (y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;
    printf("%.2lf %.2lf\n", k, b);

    return 0;
}
