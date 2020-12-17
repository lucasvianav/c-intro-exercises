#include <stdio.h>

int isRightTriangle(int a, int b, int c){
    int hip, cat1, cat2;

    if(a > b && a > c){ /* a > b, c --> a = hip */
        hip = a;
        cat1 = b;
        cat2 = c;
    }
    else if(b > a && b > c){
        hip = b;
        cat1 = a;
        cat2 = c;
    }
    else if(c > a && c > b){
        hip = c;
        cat1 = a;
        cat2 = b;
    }
    else { return 0; }
        
    if (hip*hip == cat1*cat1 + cat2*cat2){ return 1; }
    else{ return 0; }

    return -1;

}

int main(){
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int aux = isRightTriangle(a,b,c);

    if (aux == 1){ printf("SIM\n"); }
    else if (aux == 0){ printf("NAO\n"); }

    return 0;

}