#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define ROCKET_INIT_POS (FIELD_HEIGHT + 1) / 2
#define BALL_INIT_X_POS (FIELD_WIDTH) / 2
#define BALL_INIT_Y_POS (FIELD_HEIGHT + 1) / 2
#define MAX_SCORE 21
#define INITIAL_SCORE 0
/*
MODE:   10 - SOFT,
        5  - HARD,
        1  - SUPER ULTRA MEGA HARD.

*/
#define MODE 7

int ball_current_x_pos;
int ball_current_y_pos;
int rocket_r_current_pos;
int rocket_l_current_pos;
int r_score;
int l_score;
int reset;
int ball_direction;
static struct termios config;

void game_logic();
void user_input();
void drow_graphics();

int main() {
    ball_current_x_pos = BALL_INIT_X_POS;
    ball_current_y_pos = BALL_INIT_Y_POS;
    rocket_r_current_pos = ROCKET_INIT_POS;
    rocket_l_current_pos = ROCKET_INIT_POS;
    r_score = INITIAL_SCORE;
    l_score = INITIAL_SCORE;
    reset = 1;
    tcgetattr(0, &config);
    struct termios new_config = config;
    new_config.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(0, TCSANOW, &new_config);
    drow_graphics();
    while (l_score != MAX_SCORE && r_score != MAX_SCORE) {
        user_input();
        game_logic();
        drow_graphics();
        usleep(MODE * 10000);
    }
    tcsetattr(0, TCSANOW, &config);
    return 0;
}

void user_input() {
    fd_set rfds;
    struct timeval time_conf;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    time_conf.tv_sec = 0;
    time_conf.tv_usec = 0;
    if (select(2, &rfds, NULL, NULL, &time_conf)) {
        int input = getchar();
        if ((input == 'a') && (rocket_l_current_pos + 2 < FIELD_HEIGHT)) {
            rocket_l_current_pos++;
        }

        else if ((input == 'z') && (rocket_l_current_pos - 3 > 0)) {
            rocket_l_current_pos--;
        }

        else if ((input == 'k') && (rocket_r_current_pos + 2 < FIELD_HEIGHT)) {
            rocket_r_current_pos++;
        }

        else if ((input == 'm') && (rocket_r_current_pos - 3 > 0)) {
            rocket_r_current_pos--;
        }

        else if (input == ' ') {
            return;
        }
    }
}

void drow_graphics() {
    char symbol;
    int winner = (l_score > r_score) ? 1 : 2;
    printf("\033[0d\033[2J");
    for (int field_y = FIELD_HEIGHT; field_y > 0; field_y--) {
        for (int field_x = 1; field_x <= FIELD_WIDTH; field_x++) {
            if (field_y == FIELD_HEIGHT || field_y == 1 || field_x == FIELD_WIDTH || field_x == 1) {
                symbol = '*';
            } else if (ball_current_x_pos == field_x && ball_current_y_pos == field_y) {
                symbol = 'O';
            } else {
                symbol = ' ';
            }
            if (field_x == 3 && (rocket_l_current_pos == field_y || rocket_l_current_pos == field_y - 1 ||
                                 rocket_l_current_pos == field_y + 1)) {
                symbol = '|';
            }
            if (field_x == FIELD_WIDTH - 2 &&
                (rocket_r_current_pos == field_y || rocket_r_current_pos == field_y - 1 ||
                 rocket_r_current_pos == field_y + 1)) {
                symbol = '|';
            }

            if ((l_score == MAX_SCORE || r_score == MAX_SCORE) && field_y == FIELD_HEIGHT - 3 &&
                (field_x == (FIELD_WIDTH - 13) / 2)) {
                printf("PLAYER %d WON", winner);
                field_x = field_x + 11;
            } else if (field_y == FIELD_HEIGHT - 3 && field_x == (FIELD_WIDTH - 12) / 2) {
                printf("%02d  ||  %02d", l_score, r_score);
                field_x = field_x + 9;
            } else {
                printf("%c", symbol);
            }
        }
        printf("\n");
    }
}

void game_logic() {
    if (reset) {
        ball_current_x_pos = BALL_INIT_X_POS;
        ball_current_y_pos = BALL_INIT_Y_POS;
        if (r_score > l_score)
            ball_direction = 4;
        else
            ball_direction = 1;
        reset = 0;
    }

    // ball movement
    // Reflex from top/bottom wall
    if (ball_current_y_pos + 1 == FIELD_HEIGHT) {
        switch (ball_direction) {
            case 0:
                ball_direction = 2;
                break;
            case 5:
                ball_direction = 3;
                break;
        }
    } else if (ball_current_y_pos - 1 == 1) {
        switch (ball_direction) {
            case 2:
                ball_direction = 0;
                break;
            case 3:
                ball_direction = 5;
                break;
        }
    }

    // TODO ball reflection from rocket
    if (ball_current_x_pos + 1 == FIELD_WIDTH - 2) {
        if (rocket_r_current_pos == ball_current_y_pos)
            ball_direction = 4;
        else if (rocket_r_current_pos == ball_current_y_pos - 1)
            ball_direction = 3;
        else if (rocket_r_current_pos == ball_current_y_pos + 1)
            ball_direction = 5;
    } else if (ball_current_x_pos - 1 == 3) {
        if (rocket_l_current_pos == ball_current_y_pos)
            ball_direction = 1;
        else if (rocket_l_current_pos == ball_current_y_pos - 1)
            ball_direction = 2;
        else if (rocket_l_current_pos == ball_current_y_pos + 1)
            ball_direction = 0;
    }

    // TODO ball scoring
    if (ball_current_x_pos + 1 == FIELD_WIDTH) {
        l_score += 1;
        reset = 1;
    } else if (ball_current_x_pos - 1 == 0) {
        r_score += 1;
        reset = 1;
    }

    // Movement
    switch (ball_direction) {
        case 0:
            ball_current_x_pos += 1;
            ball_current_y_pos += 1;
            break;
        case 1:
            ball_current_x_pos += 1;
            break;
        case 2:
            ball_current_x_pos += 1;
            ball_current_y_pos -= 1;
            break;
        case 3:
            ball_current_x_pos -= 1;
            ball_current_y_pos -= 1;
            break;
        case 4:
            ball_current_x_pos -= 1;
            break;
        case 5:
            ball_current_x_pos -= 1;
            ball_current_y_pos += 1;
            break;
        default:
            printf("GAME IS BROKEN");
            break;
    }
}
