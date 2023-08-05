#include "data_io.h"

#include <stdio.h>

int input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            data = NULL;
            return 0;
        }
    }
    return 1;
}

int input_size(int *n) {
    if (scanf("%d", n) == 1 && *n > 0) return 1;
    return 0;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i + 1 != n) printf(" ");
    }
}