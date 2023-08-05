#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    // input(data, &n);
    if (!input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    char helper;
    if (scanf("%d%c", n, &helper) != 2 || helper != '\n' || *n > NMAX || *n <= 0) return 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &helper) != 2) return 1;
    }
    if (helper != '\n') return 1;
    return 0;
}

void output(int *a, int n) {
    char helper = ' ';
    for (int *p = a; p - a < n; p++) {
        if (p - a == n - 1) helper = '\0';
        printf("%d%c", *p, helper);
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}
