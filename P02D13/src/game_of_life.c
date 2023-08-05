#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // sleep()

#define WIDTH 80
#define HEIGHT 25

void game();
void start_game(int matrix[][WIDTH], int *speed, int *cell, int *error);
void input_matrix(int matrix[][WIDTH], int *error);
void game_logic(int matrix[][WIDTH], int *cell);
int is_alive(int matrix[][WIDTH], int r, int c);
void print_field(int matrix[][WIDTH]);
void print_game_over();

int main() {
    game();
    return 0;
}

void game() {
    // Флаг обработки ошибок
    int error = 0;
    // Скорость игры
    int speed = 5;
    // Кол-во живых клеток
    int cell = 1;

    // Инициализация поля
    int matrix[HEIGHT][WIDTH];
    input_matrix(matrix, &error);

    // Инициализация библиотеки curses
    initscr();
    // Выключаем отображение вводимых символов в wgetch()
    noecho();

    // Запуск игры
    start_game(matrix, &speed, &cell, &error);
    // Вывод GAME OVER
    print_game_over();
    // Завершение библиотеки curses
    endwin();
}

void start_game(int matrix[][WIDTH], int *speed, int *cell, int *error) {
    while (*cell && !(*error)) {
        // Ограничение по времени ожидания wgetch() в миллисекундах
        if (*speed < 1) *speed = 1;
        halfdelay(*speed);
        // Game logic
        game_logic(matrix, cell);
        // Вывод поля
        print_field(matrix);
        // Сбросить stdin терминала
        if (freopen("/dev/tty", "r", stdin)) {
            // Управление
            char move = getch();
            switch (move) {
                case 'Z':
                case 'z':
                    *speed -= 1;
                    break;
                case 'X':
                case 'x':
                    *speed += 1;
                    break;
                case 'Q':
                case 'q':
                    endwin();
                    exit(0);
                    break;
            }
        } else {
            *error = 1;
        }
        // Очистим консоль
        clear();
    }
}

void game_logic(int matrix[][WIDTH], int *cell) {
    // Кол-во живых клеток
    int count_cell = 0;
    int new_matrix[HEIGHT][WIDTH];
    for (int rows = 0; rows < HEIGHT; rows++) {
        for (int column = 0; column < WIDTH; column++) {
            new_matrix[rows][column] = is_alive(matrix, rows, column);
            if (new_matrix[rows][column]) count_cell++;
        }
    }
    for (int rows = 0; rows < HEIGHT; rows++) {
        for (int column = 0; column < WIDTH; column++) {
            matrix[rows][column] = new_matrix[rows][column];
        }
    }
    *cell = count_cell;
}

int is_alive(int matrix[][WIDTH], int line, int column) {
    // Флаг жизни клетки
    int alive = 0;
    // Флаг нахождения 3 друзей
    int alive_around = 0;

    // Проверка друзей
    for (int i = line - 1; i <= line + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            if (matrix[(i + HEIGHT) % HEIGHT][(j + WIDTH) % WIDTH]) {
                if (i == line && j == column) continue;
                alive_around++;
            }
        }
    }

    // Проверка будет ли ячейка жить
    if ((alive_around == 2 || alive_around == 3) && matrix[line][column]) {
        alive = 1;
    } else if (alive_around == 3 && !matrix[line][column]) {
        alive = 1;
    }
    return alive;
}

void print_field(int matrix[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Вывод клетки
            if (matrix[i][j]) {
                printw("o");
            } else {
                printw(" ");
            }
            //
            if (j == WIDTH - 1 && i != HEIGHT - 1) {
                printw("\n");
            }
        }
    }
    printw("\n");
    // Перенести текст на окно терминала
    refresh();
}

void print_game_over() {
    for (int y = 0; y < HEIGHT; y++) {
        if (y == HEIGHT / 2) {
            for (int x = 0; x < HEIGHT; x++) {
                if (x == 20) {
                    printw("Game Over");
                }
                printw(" ");
            }
        }
        printw("\n");
    }
    // Перенести текст на окно терминала
    refresh();
    // Остановить действие программы на 3 секунды
    sleep(3);
}

void input_matrix(int matrix[][WIDTH], int *error) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (!scanf("%d", &matrix[i][j])) *error = 1;
        }
    }
    if (i != HEIGHT || j != WIDTH) *error = 1;
}
