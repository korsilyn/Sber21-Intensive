#include "dynamic.h"

// Функция для ввода элемента в конец стека (для стека операторов)
void push_op(char* stack, int* top, char x) {
    *top = *top + 1;
    stack[*top] = x;
}

// Функция для вывода последнего элемента стека (для стека операторов)
char pop_op(const char* stack, int* top) {
    char x = stack[*top];
    *top = *top - 1;
    return x;
}

// Функция для ввода элемента в конец стека (для стека цифр)
void push_num(double* stack, int* top, double x) {
    *top = *top + 1;
    stack[*top] = x;
}

// Функция для вывода последнего элемента стека (для стека цифр)
double pop_num(const double* stack, int* top) {
    double x = stack[*top];
    *top = *top - 1;
    return x;
}