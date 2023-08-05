#include "logger.h"

FILE* log_init(char* filename) {
    FILE* fp;
    fp = fopen(filename, "a");
    return fp;
}

int logcat(FILE* log_file, char* message, log_level level) {
    char* log_lvl = string_from_enum(level);
    int error = 0;
    if (log_lvl == NULL)
        error = 1;
    else {
        while (log_lvl != '\0') {
            fputc(str, log_file);
        }
        while (message != '\0') {
            fputc(str, log_file);
        }
        fputc('\n', log_file);
    }
    return error;
}

char* string_from_enum(enum log_level level) {
    char* strings[] = {"debug", "trace", "info", "warning", "error"};
    return strings[level];
}

int log_close(FILE* log_file) { fclose(log_file); }
