#include <stdio.h>
#define NMAX 10

int input(int* buffer, int* length, int* shift);
void output(int* buffer, int length);
void array_shift(int* buffer, int length, int* shift);

int main() {
    int n, shift, data[NMAX];
    if (!input(data, &n, &shift)) {
        array_shift(data, n, &shift);
        output(data, n);
    } else
        printf("n/a");
}

int input(int* buffer, int* length, int* shift) {
    if (scanf("%d", length) != 1 || *length > NMAX || *length <= 0) return 1;
    for (int* p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) return 1;
    }
    if (scanf("%d", shift) != 1) return 1;
    return 0;
}

void output(int* buffer, int length) {
    char helper = ' ';
    for (int* p = buffer; p - buffer < length; p++) {
        if (p - buffer == length - 1) helper = '\0';
        printf("%d%c", *p, helper);
    }
}

void array_shift(int* buffer, int length, int* shift) {
    int direction = (*shift < 0) ? 0 : 1;
    while (*shift) {
        if (direction) {
            int temp = buffer[0];
            for (int i = 0; i < length - 1; i++) buffer[i] = buffer[i + 1];
            buffer[length - 1] = temp;
            *shift = *shift - 1;
        } else {
            int temp = buffer[length - 1];
            for (int i = length - 1; i > 0; i--) buffer[i] = buffer[i - 1];
            buffer[0] = temp;
            *shift = *shift + 1;
        }
    }
}