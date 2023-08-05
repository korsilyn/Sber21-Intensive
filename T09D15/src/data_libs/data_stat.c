#include "data_stat.h"

double max(const double *data, int n) {
    double max_v = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max_v) max_v = data[i];
    }
    return max_v;
}

double min(const double *data, int n) {
    double min_v = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min_v) min_v = data[i];
    }
    return min_v;
}

double mean(const double *data, int n) {
    double mean_v = 0.0;
    for (int i = 0; i < n; i++) {
        mean_v += data[i];
    }
    return mean_v / (double)n;
}

double variance(double *data, int n) {
    double mean_v = mean(data, n);
    double variance_v = 0.0;
    for (int i = 0; i < n; i++) {
        variance_v += (data[i] - mean_v) * (data[i] - mean_v);
    }
    return variance_v / (double)n;
}
