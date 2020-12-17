#include <stdio.h>
#include <math.h>

int main(){
    double a, b;

    scanf("%lf %lf", &a, &b);

    double r = pow(a,b);

    printf("%.4lf\n", r);

    return 0;

}