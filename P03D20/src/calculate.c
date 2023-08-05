#include "calculate.h"

// Функция для подсчета значения выражения
// Она принимает х для случаев, когда в выражении есть х
double calculate(char* postfix, double x) {
    double nums[200];   // Стек для цифр
    char* e = postfix;  // Указатель, для перебоора массива
    int top = -1;  // Показывает, на сколько далеко мы от головы стека. -1 значит, что стека нет
    int check_if_double = 0;  // Проверка, double ли число
    while (*e != '\0') {
        // Если мы встречаем х, то сразу скармливаем в стек отправленное число
        if (*e == 'x') push_num(nums, &top, x);
        // Просто собираем все числа в стек чисел
        else if (((int)*e >= 48 && (int)*e <= 57)) {
            double cur_num = 0;
            // Я делил при конверции в постфикс числа пробелами, чтобы потом забирать числа
            // Пока не встретится пробел
            while (*e != ' ') {
                // Если мы не видим точку, и флаг неактивен, то мы просто собираем число
                if (*e != '.' && !check_if_double) {
                    // Допустим есть число 1, приходит еще 5
                    // 1 * 10 = 10 и прибавляем 5, получаем 15
                    cur_num = cur_num * 10 + (double)(*e - 48);
                    e++;
                    // Если мы встречаем точку, то значит число будет double
                } else if (*e == '.' && !check_if_double) {
                    e++;
                    check_if_double = 1;
                    // Дальше коллекционируем цифры после запятой
                } else {
                    // Мы берем текущее число, допустим 1, и прибавляем новое / 10 в 1 степени
                    // Каждый раз будет больше степень, допустим число 1.1 + 5 / 10^2
                    cur_num = cur_num + (double)(*e - 48) / pow(10, check_if_double);
                    e++;
                    // Мы увеличиваем количество знаков после запятой
                    check_if_double++;
                }
            }
            e--;
            check_if_double = 0;
            // Пушим получившееся число в массив
            push_num(nums, &top, cur_num);
        }
        // Если это не число и не пробел, значит знак
        else if (*e != ' ')
            calc(e, nums, &top);
        e++;
    }
    // Возвращаем единственное оставшееся число в стеке, то есть результат
    return pop_num(nums, &top);
}

// Функция для декомпозиции
// Производит все действия с числами и знаками
void calc(char* e, double* nums, int* top) {
    // Мы всегда собираем первое число
    // Второе число берется только в случае +-*/
    double num1 = pop_num(nums, top);
    double num2, result;
    // Очень банальные операции, в зависимости от знака делаем действия
    // Буквы были описаны в парсе
    switch (*e) {
        case '+':
            num2 = pop_num(nums, top);
            result = num2 + num1;
            break;
        case '-':
            num2 = pop_num(nums, top);
            result = num2 - num1;
            break;
        case '*':
            num2 = pop_num(nums, top);
            result = num2 * num1;
            break;
        case '/':
            num2 = pop_num(nums, top);
            result = num2 / num1;
            break;
        case 's':
            result = sin(num1);
            break;
        case 'c':
            result = cos(num1);
            break;
        case 't':
            result = tan(num1);
            break;
        case 'g':
            // ctg это обратный тангенс, в math.h нету его, поэтому так
            result = 1 / tan(num1);
            break;
        case 'q':
            result = sqrt(num1);
            break;
        case 'n':
            result = log(num1);
            break;
        default:
            printf("\nInvalid expression, exiting...\n\n");
            exit(1);  // !!!ALERT УБРАТЬ!!!
    }
    // Пушим получившийся результат в стек 
    push_num(nums, top, result);
}