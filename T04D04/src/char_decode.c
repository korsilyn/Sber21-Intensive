#include <stdio.h>

void encode();
void decode();

int main(int argc, char *argv[]) {
  int mode = -1;
  if (argc == 2 && (*argv[1] == 49 || *argv[1] == 48))
    mode = *argv[1] - 48;
  if (mode == 0)
    encode();
  else if (mode == 1)
    decode();
  else
    printf("n/a");
}

void encode() {
  char input;
  char helper;
  while (1) {
    if (scanf("%c%c", &input, &helper) == 2 && helper != ' ' &&
        helper != '\n') {
      printf("n/a");
      break;
    }
    printf("%X", input);
    if (helper == ' ')
      printf(" ");
    else if (helper == '\n')
      break;
  }
}

void decode() {
  int input;
  char helper;
  while (1) {
    if (scanf("%X%c", &input, &helper) == 2 && helper != ' ' &&
        helper != '\n') {
      printf("n/a");
      break;
    }
    if (input > 0xff || input < 0x10) {
      printf("n/a");
      break;
    }
    printf("%c", input);
    if (helper == ' ')
      printf(" ");
    else if (helper == '\n')
      break;
  }
}