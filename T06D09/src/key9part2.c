#include <stdio.h>

#define LEN 100

int input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int first_number[LEN], len1, second_number[LEN], len2, result_len;
    if (!input(first_number, &len1) && !input(second_number, &len2)) {
        int result[LEN + 1];
        sum(first_number, len1, second_number, len2, result, &result_len);
        output(result, result_len);
        printf("\n");
        sub(first_number, len1, second_number, len2, result, &result_len);
        output(result, result_len);
    } else
        printf("n/a");
}

int input(int *buffer, int *length) {
    char helper;
    *length = 0;
    for (int *p = buffer; p - buffer < LEN; p++) {
        if (scanf("%d%c", p, &helper) == 2 && (helper == '\n' || helper == ' ')) {
            if (*p >= 0 && *p < 10)
                *length = *length + 1;
            else
                return 1;
            if (helper == '\n') break;
        } else
            return 1;
    }
    return 0;
}

void output(int *buffer, int length) {
    char helper = ' ';
    int count = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (i == 0) {
            count++;
            helper = '\0';
        }
        if (buffer[length - i] == 0 && count == 0)
            continue;
        else {
            printf("%d%c", buffer[length - i], helper);
            count++;
        }
    }
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int overflow = 0;
    int diff = 0;
    int count = 0;
    if (len1 > len2) {
        *result_length = len1;
        diff = len1 - len2;
    } else {
        *result_length = len2;
        diff = len2 - len1;
    }
    for (int i = *result_length; i >= 0; i--) {
        int num = 0;
        int num1 = 0;
        int num2 = 0;
        if (len1 >= len2 && len1 - 1 - i >= 0)
            num1 = buff1[i];
        else if (len1 < len2 && len1 - 1 - i >= 0 - diff && i != 0 && count < len1) {
            num1 = buff1[i - diff];
            count++;
        }
        if (len2 >= len1 && len2 - 1 - i >= 0)
            num2 = buff2[i];
        else if (len2 < len1 && len2 - 1 - i >= 0 - diff && i != 0 && count < len2) {
            num2 = buff2[i - diff];
            count++;
        }
        num = num1 + num2;
        if (overflow) {
            num++;
            overflow--;
        }
        if (num / 10) overflow++;
        result[i + 1] = num % 10;
    }
    if (overflow) {
        *result_length = *result_length + 1;
        for (int i = *result_length; i > 0; i--) result[i] = result[i - 1];
        result[1] = 1;
    }
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result, int *result_length) {
    int underflow = 0;
    int diff = 0;
    int count = 0;
    if (len1 > len2) {
        *result_length = len1;
        diff = len1 - len2;
    } else {
        *result_length = len2;
        diff = len2 - len1;
    }
    for (int i = *result_length - 1; i >= 0; i--) {
        int num = 0;
        int num1 = 0;
        int num2 = 0;
        if (len1 >= len2 && len1 - 1 - i >= 0)
            num1 = buff1[i];
        else if (len1 < len2 && len1 - 1 - i >= 0 - diff && i != 0 && count < len1) {
            num1 = buff1[i - diff];
            count++;
        }
        if (len2 >= len1 && len2 - 1 - i >= 0)
            num2 = buff2[i];
        else if (len2 <= len1 && len2 - 1 - i >= 0 - diff && i != 0 && count < len2) {
            num2 = buff2[i - diff];
            count++;
        }
        num = num1 - num2;
        if (underflow) {
            num--;
            underflow--;
        }
        if (num < 0) {
            underflow++;
            result[i + 1] = 10 + num % 10;
        } else
            result[i + 1] = num;
    }
    if (underflow) {
        printf("n/a");
        *result_length = 0;
    }
}
