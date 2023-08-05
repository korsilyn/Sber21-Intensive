#include <stdio.h>
#define NMAX 10

int input(int* a);
void output(int* a);
void quick_sort(int* a, int low, int high);
int split(int* a, int low, int high);
void heap_sort(int* a);
void heapify(int* a, int n, int i);
void swap(int* a, int* b);
void copyarr(const int* a, int* copy);

int main() {
    int data[NMAX];
    if (!input(data)) {
        int copy[NMAX];
        copyarr(data, copy);
        quick_sort(data, 0, NMAX - 1);
        output(data);
        printf("\n");
        heap_sort(copy);
        output(copy);
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

int split(int* a, int low, int high) {
    int pivot = a[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return (i + 1);
}

void quick_sort(int* a, int low, int high) {
    if (low < high) {
        int pivot = split(a, low, high);

        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}

void heapify(int* a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) largest = left;

    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int* a) {
    for (int i = NMAX / 2 - 1; i >= 0; i--) heapify(a, NMAX, i);
    for (int i = NMAX - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copyarr(const int* a, int* copy) {
    for (int i = 0; i < NMAX; i++) copy[i] = a[i];
}