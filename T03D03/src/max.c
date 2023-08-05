#include <stdio.h>

int max(int a, int b);

int main() {
    int a = 0;
    int b = 0;
    if (scanf("%d%d", &a, &b) != 2)
        printf("n/a");
    else
        printf("%d", max(a, b));
    return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
