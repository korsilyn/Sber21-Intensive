#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else
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

void output(int *a, int n) {
    char helper = ' ';
    for (int *p = a; p - a < n; p++) {
        if (p - a == n - 1) helper = '\n';
        printf("%d%c", *p, helper);
    }
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int n) {
    int max_v = a[0];
    for (int *p = &a[1]; p - a < n; p++) {
        if (*p > max_v) max_v = *p;
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = a[0];
    for (int *p = &a[1]; p - a < n; p++) {
        if (*p < min_v) min_v = *p;
    }
    return min_v;
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
