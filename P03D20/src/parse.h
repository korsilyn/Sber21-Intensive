#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>

#include "dynamic.h"

// Ввод выражения
char* input_arr(void);
// Сила оператора
int precedence(char op);
// Проверка на базовые операторы
int is_op(char ch);
// Конвертация в постфикс
char* convert(char* input, int len);
// Проверка на функцию
int is_func(const char* input, int i, int len);
// Функция для декомпозиции + работа с операторами
void push_ops(char* input, int* i, int* j, int* len, char* result, int* top, char* stack);

#endif