#include <stdio.h>

int main(){
    double x = 0.0;
    double y = 0.0;
    if (scanf("%lf%lf", &x, &y) != 2)
        printf("n/a");
    else {
        if (((x * x) + (y * y)) < 255555) {
            printf("GOTCHA");
        }
        else {
            printf("MISS");
        }
    }
    return 0;
}
