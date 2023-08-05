#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main(void) {
    int n;

    if (input_size(&n)) {
        double *data;
        data = malloc(n * sizeof(double));
        if (input(data, n) && data != NULL) {
            if (make_decision(data, n))
                printf("YES");
            else
                printf("NO");
        } else
            printf("n/a");
        if (data != NULL) free(data);
    } else
        printf("n/a");
}
