/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        int sum = sum_numbers(data, n);
        if (sum != 1) {
            printf("%d\n", sum);
            int numbers[NMAX];
            int new_length = find_numbers(data, n, sum, numbers);
            output(numbers, new_length);
        } else
            printf("n/a");
    }
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length > NMAX || *length <= 0) return 1;
    for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1) return 1;
    }
    return 0;
}

void output(int *buffer, int length) {
    char helper = ' ';
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer == length - 1) helper = '\0';
        printf("%d%c", *p, helper);
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            count++;
        }
    }
    if (count == 0) sum = 1;
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }

    return count;
}
