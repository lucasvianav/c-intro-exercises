#include <stdio.h>
#include <math.h>

int main(){
    float a_1, a_n, S, q, n;

    scanf("%f %f %f", &a_1, &q, &n);

    a_n = a_1*pow(q,n-1);
    S = (a_1*(pow(q,n) - 1)/(q-1));

    printf("%.2f\n", a_n);
    printf("%.2f\n", S);

    return 0;
    
}