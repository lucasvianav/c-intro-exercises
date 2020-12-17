#include <stdio.h>
#include <stdlib.h>

#define SIZE 31

int main(){
    int *vector = (int *)malloc(SIZE * sizeof(int));

    // receives the input vector
    for(int i = 0; i < SIZE; i++){ scanf("%d", &vector[i]); }

    // goes through the whole vector (except the last number)
    for(int i = 0; i < SIZE - 1; i++){ 
        // checks if each element is divisible by the last one
        if(vector[i] % vector[SIZE-1] == 0){ printf("%d\n", vector[i]); }
    }

    free(vector);

    return 0;

}