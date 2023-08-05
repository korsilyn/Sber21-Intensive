/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void check_number(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    // input(data, &n);
    if (!input(data, &n))
        check_number(data, n);
    else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    char helper;
    if (scanf("%d%c", n, &helper) != 2 || helper != '\n' || *n > NMAX || *n <= 0) return 1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &helper) != 2) return 1;
    }
    if (helper != '\n') return 1;
    return 0;
}

void check_number(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);
    int found_v = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean_v && *p <= (mean_v + 3 * sqrt(variance_v)) && *p != 0) {
            printf("%d", *p);
            found_v = 1;
            break;
        }
    }
    if (!found_v) printf("0");
}

double mean(int *a, int n) {
    double mean_v = 0.0;
    for (int *p = a; p - a < n; p++) {
        mean_v += *p;
    }
    return mean_v / n;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = 0.0;
    for (int *p = a; p - a < n; p++) {
        variance_v += (*p - mean_v) * (*p - mean_v);
    }
    return variance_v / n;
}
