#include <stdio.h>

float calculator(float a, char op, float b){
    switch(op){
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
        case '%':
            return ((a / b) * 100.0);

    }

    return -1;
}

int main(){
    float n1, n2;
    char op;

    scanf("%f %c %f", &n1, &op, &n2);

    printf("%f\n", calculator(n1,op,n2));

    return 0;
}