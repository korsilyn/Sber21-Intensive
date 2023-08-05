#include <stdio.h>
#include <stdlib.h>

int input(int* a, int n);
void output(int* a, int n);
void bubble_sort(int* a, int n);
void swap(int* a, int* b);

int main() {
    int* data = NULL;
    int n = 0;
    int error = 0;
    if (scanf("%d", &n) == 1) {
        data = (int*)malloc(n * sizeof(int));
        error = input(data, n);
    } else
        printf("n/a");
    if (error) printf("n/a");
    if (data != NULL) {
        bubble_sort(data, n);
        output(data, n);
        free(data);
    } else
        printf("n/a");
    return 0;
}

int input(int* a, int n) {
    int error = 0;
    for (int* p = a; p - a < n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a");
            error = 1;
            break;
        }
    }
    return error;
}

void output(int* a, int n) {
    char helper = ' ';
    for (int* p = a; p - a < n; p++) {
        if (p - a == n - 1) helper = '\0';
        printf("%d%c", *p, helper);
    }
}

void bubble_sort(int* a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
