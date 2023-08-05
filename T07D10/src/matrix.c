#include <stdio.h>
#include <stdlib.h>

#define XMAX 100
#define YMAX 100

int input_static(int* a, int* row, int* column);
//from every input call output
//create array inside func
int input_dynamic_1();
int input_dynamic_2();
int input_dynamic_3();
void output(int* a, int row, int column);

int main() {
    int* data = NULL;
    int data_static[XMAX][YMAX];
    int type = 0;
    int error = 0;
    int row = 0;
    int column = 0;
    if (scanf("%d", &type) == 1) {
        switch (type) {
            case (1):
                if (!input_static(*data_static, &row, &column))
                    output(*data_static, row, column);
                else
                    printf("n/a");
                break;
            case (2):
                error = input_dynamic_1();
                break;
            case (3):
                error = input_dynamic_2();
                break;
            case (4):
                error = input_dynamic_3();
                break;
            default:
                printf("n/a");
                break;
        }
    } else
        printf("n/a");
    // if (error)
    //     printf("n/a");
    // else if (data != NULL && type != 1) {
    //     output(data, x, y);
    //     free(data);
    // } else
    //     printf("n/a");
    return 0;
}

int input_static(int* a, int* row, int* column) {
    int error = 0;
    if (scanf("%d%d", row, column) != 2)
        error = 1;
    else {
        for (int i = 0; i < *row; i++) {
            for (int j = 0; j < *column; j++) {
                if (scanf("%d", (a + i * *column + j)) != 1) {
                    printf("n/a");
                    error = 1;
                    break;
                }
            }
        }
    }
    return error;
}

void output(int* a, int row, int column) {
    char helper = ' ';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i + 1 == row && j + 1 == column)
                helper = '\0';
            else if (j + 1 == column)
                helper = '\n';
            else
                helper = ' ';
            printf("%d%c", *(a + i * column + j), helper);
        }
    }
}

int input_dynamic_1() {}
int input_dynamic_2() {}
int input_dynamic_3() {}