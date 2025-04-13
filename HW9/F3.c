#include <stdio.h>
int main() {
    char c;
    int count[10] = {0};
    while ((c = getchar()) != '\n')
        if (c >= '0' && c <= '9') count[c-'0']++;
    for (int d = 0; d < 10; d++)
        if (count[d]) printf("%d %d\n", d, count[d]);
}
