#include <stdio.h>

void decomposeInCoins(int value, int *cent1, int *cent5, int *cent10, int *cent25, int *cent50, int *real1){
    // começando da maior pra menor, a quantidade de cada moeda vai ser o valor que falta decompor
    // (value) dividido pelo valor da respectiva moeda (em centavos) - resultado arredondado para baixo
    // o valor que falta decompor, então, se torna o resto dessa divisão
    *real1 = value/100; value %= 100; // 1 real = 100 centavos
    *cent50 = value/50; value %= 50;
    *cent25 = value/25; value %= 25;
    *cent10 = value/10; value %= 10;
    *cent5 = value/5; value %= 5;
    *cent1 = value;
    
    return;
}

int main(){
    int value; // valor a ser decomposto em moedas
    int cent1, cent5, cent10, cent25, cent50, real1; // quantidade de cada moeda

    // recebe o input do valor total
    scanf("%d", &value);

    // faz a decomposição (cálculo da quantidade necessária de cada moeda)
    decomposeInCoins(value, &cent1, &cent5, &cent10, &cent25, &cent50, &real1);

    // printa output
    printf("O valor consiste em %d moedas de 1 real\nO valor consiste em %d moedas de 50 centavos\nO valor consiste em %d moedas de 25 centavos\nO valor consiste em %d moedas de 10 centavos\nO valor consiste em %d moedas de 5 centavos\nO valor consiste em %d moedas de 1 centavo\n",
        real1, cent50, cent25, cent10, cent5, cent1
    );

    return 0;
}