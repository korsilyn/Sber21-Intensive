#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
    int n;

    if (input_size(&n)) {
        double *data;
        data = malloc(n * sizeof(double));
        if (input(data, n) && data != NULL) {
            if (normalization(data, n))
                output(data, n);
            else
                printf("ERROR");
        } else
            printf("ERROR");
        if (data != NULL) free(data);
    } else
        printf("ERROR");

    return 0;
}
