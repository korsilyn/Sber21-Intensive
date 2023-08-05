#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES

double agnesi(double x);
double bernoulli(double x);
double hyperbola(double x);

int main() {
  double y1 = 0.0;
  double y2 = 0.0;
  double y3 = 0.0;
  for (double pi = -M_PI; pi < M_PI; pi += M_PI / 20.5) {
    y1 = agnesi(pi);
    y2 = bernoulli(pi);
    if (y2 != y2) y2 = -9999;
    y3 = hyperbola(pi);
    printf("%.7lf | %.7lf | ", pi, y1);
    y2 == -9999 ? printf("- | ") : printf("%.7lf | ", y2);
    printf("%.7lf\n", y3);
  }
}

double agnesi(double x) { return (pow(1, 3)) / (pow(1, 2) + pow(x, 2)); }

double bernoulli(double x) {
  double temp = sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2));
  return sqrt(temp - pow(x, 2) - pow(1, 2));
}

double hyperbola(double x) { return 1 / pow(x, 2); }