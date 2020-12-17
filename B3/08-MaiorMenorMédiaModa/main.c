#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_SIZE 10

int maior(int vector[VECTOR_SIZE]){
    int maior = 0;

    // Varre o vetor buscando o maior número
    for(int i = 0; i < VECTOR_SIZE; i++){ maior = (maior < vector[i]) ? vector[i] : maior; }

    return maior;
}

int menor(int vector[VECTOR_SIZE]){
    int menor = vector[0];

    // Varre o vetor buscando o menor número
    for(int i = 1; i < VECTOR_SIZE; i++){ menor = (menor > vector[i]) ? vector[i] : menor; }

    return menor;
}

float media(int vector[VECTOR_SIZE]){
    float media = 0;

    // Soma todos os números
    for(int i = 0; i < VECTOR_SIZE; i++){ media += vector[i]; }

    // E divide pela quantidade (calculando a média)
    media /= (float)VECTOR_SIZE;

    return media;
}

int moda(int vector[VECTOR_SIZE]){
    // Vetor com os contadores de quantas vezes cada elemento do vetor analisado aparece
    // Ele vai ter tamanho igual ao valor do maior número no vetor analisado
    int size = maior(vector) + 1;
    int *contadores = (int *)malloc(size * sizeof(int));
    memset(contadores, 0, size * sizeof(int)); // Todos são inicialmente 0

    // Conta quantos de cada número o vetor possuir
    for(int i = 0; i < VECTOR_SIZE; i++){ contadores[vector[i]]++; }

    // Checa qual número apareceu mais vezes
    int moda = vector[0];
    for(int i = 1; i < VECTOR_SIZE; i++){ moda = (contadores[moda] < contadores[vector[i]]) ? vector[i] : moda; }

    free(contadores);

    return moda;
}

int main(){
    int vector[VECTOR_SIZE];

    for(int i = 0; i < VECTOR_SIZE; i++){ scanf("%d", &vector[i]); }

    printf("%d %d %.2f %d\n", maior(vector), menor(vector), media(vector), moda(vector));

    return 0;
}