#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic.h"

// Функция для подсчета значения выражения
// Она принимает х для случаев, когда в выражении есть х
double calculate(char* postfix, double x);
// Функция для декомпозиции
// Производит все действия с числами и знаками
void calc(char* e, double* nums, int* top);

#endif