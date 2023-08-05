#include <stdio.h>

int fibonacchi(int a);

int main() {
  int a = 0;
  if (scanf("%d", &a) != 1)
    printf("n/a");
  else
    printf("%d", fibonacchi(a));
  return 0;
}

int fibonacchi(int a) {
  if (a == 0) {
    return 0;
  } else if (a == 1) {
    return 1;
  } else {
    return fibonacchi(a - 1) + fibonacchi(a - 2);
  }
}