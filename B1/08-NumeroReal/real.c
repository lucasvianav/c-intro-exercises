#include <stdio.h>
#include <math.h>

int main(){
    double a;

    scanf("%lf", &a);

    int intPart = (int) a;
    double decPart = a - (double) intPart;
    int rounded = round(a);

    printf("%d\n", intPart);
    printf("%.4lf\n", decPart);
    printf("%d\n", rounded);

    return 0;
}