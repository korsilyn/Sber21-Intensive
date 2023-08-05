#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef Q1
#include "print_module.h"
#endif
#ifdef Q2
#include "documentation_module.h"
#endif

int main() {
#ifdef Q1
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%H:%M:%S", tm_info);

    print_log(&print_char, Log_prefix);
    print_log(&print_char, " ");
    print_log(&print_char, buffer);
    print_log(&print_char, " ");
    print_log(&print_char, Module_load_success_message);
#endif
#ifdef Q2
    int* availability_mask = check_available_documentation_module(&validate, Documents_count, Documents);

    print_docs(availability_mask, Documents_count, Documents);
    if (availability_mask != NULL) free(availability_mask);
#endif
    return 0;
}
