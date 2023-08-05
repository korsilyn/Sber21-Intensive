#include <stdio.h>
#define NMAX 10

int input(int* a);
void output(int* a);
void bubble_sort(int* a);
void swap(int* a, int* b);

int main() {
    int data[NMAX];
    if (!input(data)) {
        bubble_sort(data);
        output(data);
    } else
        printf("n/a");
    return 0;
}

int input(int* a) {
    for (int* p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) return 1;
    }
    return 0;
}

void output(int* a) {
    char helper = ' ';
    for (int* p = a; p - a < NMAX; p++) {
        if (p - a == NMAX - 1) helper = '\0';
        printf("%d%c", *p, helper);
    }
}

void bubble_sort(int* a) {
    for (int i = 0; i < NMAX - 1; i++)
        for (int j = 0; j < NMAX - i - 1; j++)
            if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}