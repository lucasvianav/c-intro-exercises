#include <stdio.h>

double min(double arr[], int len){
    double minValue = arr[0];

    for(int i = 1; i < len; i++){ if(arr[i] < minValue){ minValue = arr[i]; } }

    return minValue;
}

double discAvg(double a, double b, double c, double d){
    double numbers[] = { a, b, c, d };

    double avg = ( a + b + c + d - min(numbers, 4) ) / 3.0;

    return avg;
}

int main(){
    double a, b, c, d;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    printf("%.4lf\n", discAvg(a,b,c,d));

    return 0;

}