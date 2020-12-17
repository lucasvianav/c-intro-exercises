#include <stdio.h>
#include <stdlib.h>

// retorna o valor máximo dentre os números contidos no vetor list
int max(int *list, int size){
    int out = list[0];

    // compara todos os números
    for(int i = 1; i < size; i++){
        if(list[i] > out){ out = list[i]; }
    }

    return out;
}

// retorna o valor mínimo dentre os números contidos no vetor list
int min(int *list, int size){
    int out = list[0];

    // compara todos os números
    for(int i = 1; i < size; i++){
        if(list[i] < out){ out = list[i]; }
    }

    return out;
}

int main(){
    int size; // número de números (tamanho do vetor)

    // recebe o tamanho do input
    scanf("%d", &size);
    int *vector = (int *)malloc(size *sizeof(int)); // vetor de números


    // recebe o input
    for(int i = 0; i < size; i++){
        scanf("%d", &vector[i]);
    }

    // printa o output
    printf("max: %d\n", max(vector, size));
    printf("min: %d\n", min(vector, size));

    // desaloca memória
    free(vector);

    return 0;

}