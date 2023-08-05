#include "print_module.h"

#include <stdio.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    for (int i = 0; message[i] != '\0'; i++) (*print)(message[i]);
}
