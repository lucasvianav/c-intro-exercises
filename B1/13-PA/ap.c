#include <stdio.h>

int main(){
    long a_1, a_n, S, r, n;

    scanf("%ld %ld %ld", &a_1, &r, &n);

    a_n = a_1 + (n-1)*r;
    S = n*(a_1+a_n)/2;

    printf("%ld\n", a_n);
    printf("%ld\n", S);

    return 0;
    
}