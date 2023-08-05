#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int prod(int a, int b);
void quot(int a, int b);

int main() {
    int a = 0;
    int b = 0;
    if (scanf("%d%d", &a, &b) != 2)
        printf("n/a");
    else {
        printf("%d %d %d ", sum(a, b), diff(a, b), prod(a, b));
        quot(a, b);
    }
    return 0;
}

int sum(int a, int b) {
    return (a + b);
}

int diff(int a, int b) {
    return (a - b);
}

int prod(int a, int b) {
    return (a * b);
}

void quot(int a, int b) {
    if (b != 0)
        printf("%d", a / b);
    else
        printf("n/a");
}
