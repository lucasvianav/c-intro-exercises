#include <stdio.h>

// Descomentar para abrir a possibilidade de expoentes negativos.

// double poW(int a, int b){
int poW(int a, int b){
    if(a == 1){ return a; }

    // double c = 1;
    int c = 1;

    for(int i = 0; i < b; i++){ 
        if(b > 0){ c = c*a; }
        // else if(b < 0){ c = c/a; }
    }

    return c;

}

int main(){
    int x, y;

    scanf("%d %d", &x, &y);

    // printf("%lf\n", poW(x,y));
    printf("%d\n", poW(x,y));

    return 0;

}