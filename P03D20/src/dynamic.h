#ifndef DYNAMIC_H
#define DYNAMIC_H

// Функция для ввода элемента в конец стека (для стека операторов)
void push_op(char* stack, int* top, char x);
// Функция для вывода последнего элемента стека (для стека операторов)
char pop_op(const char* stack, int* top);
// Функция для ввода элемента в конец стека (для стека цифр)
void push_num(double* stack, int* top, double x);
// Функция для вывода последнего элемента стека (для стека цифр)
double pop_num(const double* stack, int* top);

#endif