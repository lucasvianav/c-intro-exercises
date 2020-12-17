#include <stdio.h>
#include <math.h>

void primeDecomposition(int n){
    if(n > 0){ // can't decompose 0 or negative number

        // div: prime factors (starting by the lowest, 2)
        // count: prime factor's multiplicity
        for(int count = 0, div = 2; div <= sqrt(n); count = 0){
            while(n % div == 0){ // while n is divisible by div, do it
                count++;
                n /= div;
            }

            // prints that factor and it's multiplicity
            if(count > 0){ printf("%d %d\n", div, count); }

            // 2 --> 3
            if(div == 2){ div++; }

            // 3 --> 5 --> 7 --> 9
            // beacause all even number were already accounted for by the 2 factor
            else{ div += 2; }
        }

        // If n is prime integer > 1
        if(n > 1){ printf("%d 1\n", n); }
    }

    return;
}

int main(){
    int n;

    // receives the input number
    scanf("%d", &n);

    primeDecomposition(n);

    return 0;

}