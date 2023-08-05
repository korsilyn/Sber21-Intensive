#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main(void) {
    int n;

    printf("LOAD DATA...\n");
    if (input_size(&n)) {
        double *data;
        data = malloc(n * sizeof(double));
        if (input(data, n) && data != NULL) {
            printf("RAW DATA:\n\t");
            output(data, n);

            int decision = make_decision(data, n);

            printf("\nNORMALIZED DATA:\n\t");
            normalization(data, n);
            output(data, n);

            printf("\nSORTED NORMALIZED DATA:\n\t");
            sort(data, n);
            output(data, n);

            printf("\nFINAL DECISION:\n\t");
            if (decision)
                printf("YES");
            else
                printf("NO");
        }
        if (data != NULL) free(data);
    } else
        printf("n/a");
}
