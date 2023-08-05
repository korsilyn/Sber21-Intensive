#include <stdio.h>

int mod(int num, int by);
int divide(int num, int by);

int main() {
  int input = 0;
  int div = 2;
  char helper;
  int max = 0;
  if (scanf("%d%c", &input, &helper) == 2 && helper == '\n') {
    if (input < 0)
      input = -input;
    while (input != 0) {
      if (mod(input, div) != 0)
        div++;
      else {
        max = input;
        input = divide(input, div);
        if (input == 1) {
          printf("%d", max);
          break;
        }
      }
    }
  } else
    printf("n/a");
}

int mod(int num, int by) {
  while (num > 0 && num >= by)
    num -= by;
  return num;
}

int divide(int num, int by) {
  int count = 0;
  while (num > 0 && num >= by) {
    num -= by;
    count++;
  }
  return count;
}