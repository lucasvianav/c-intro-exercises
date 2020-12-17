#include <stdio.h>

// |e| = e ; |-e| = e
int abs(int e){
    if(e < 0){ e *= -1; }

    return e;

}

// a^b
float expc(float a, int b){
    float result = a; // valor do output

    // x^y
    // b > 0 ou b < 0
    if(b != 0){
        // multiplica result por a b - 1 vezes (potência)
        for(int i = 1; i < abs(b); i++){ result *= a; }
    }

    // x^0 = 1
    else{
        result = 1;
    }

    // x^(-y) = 1/x^y
    if(b < 0){
        result = 1/result;
    }

    return result;
}

int main(){
    float a;
    int b;

    // recebe o input
    scanf("%f", &a);
    scanf("%d", &b);

    float e = expc(a, b);

    printf("%.4f\n", e);

    return 0;

}