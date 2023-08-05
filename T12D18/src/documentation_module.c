#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    int* result = malloc(document_count * sizeof(int));
    va_start(args, document_count);

    for (int i = 0; i < document_count; i++) result[i] = (*validate)(va_arg(args, char*));

    va_end(args);
    return result;
}

void print_docs(int* availability, int document_count, ...) {
    va_list args;
    va_start(args, document_count);

    for (int i = 0; i < document_count; i++) {
        if (availability[i])
            printf("[%s: available]", (va_arg(args, char*)));
        else
            printf("[%s: unavailable]", (va_arg(args, char*)));
        if (i + 1 != document_count) printf("\n");
    }

    va_end(args);
}
