#include <stdlib.h>
#include <string.h>

#include "draw.h"
#include "parse.h"

int main(void) {
    char* input = input_arr();
    if (input != NULL) {
        int len = strlen(input);
        char* postfix = convert(input, len);
        if (postfix != NULL) {
            for (int i = 0; i < (int)strlen(postfix); i++) {
                printf("%c", postfix[i]);
            }
            printf("\n");
            out(postfix);
            free(postfix);
        }
        free(input);
    }

    return 0;
}