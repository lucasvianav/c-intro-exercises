#include <stdio.h>

#define NUMBER_OF_POINTS 5 // 5 pontos distintos

int main(){
    int x[NUMBER_OF_POINTS]; // vetor com os valores da coordenada x dos pontos
    int y[NUMBER_OF_POINTS]; //  ||    ||  ||   ||    ||    ||     y  ||    ||
    int index = 0; // índice do ponto com a maior média
    float mean; // maior média
    float tmp; // variável auxiliar

    // recebe o input
    for(int i = 0; i < NUMBER_OF_POINTS; i++){
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    
    // encontra o ponto com a maior média
    mean = (x[0]+y[0])/2.0;
    for(int i = 0; i < NUMBER_OF_POINTS; i++){ 
        tmp = (x[i]+y[i])/2.0;

        if(tmp > mean){
            mean = tmp;
            index = i;
        }
    }

    // printa o resultado
    printf("%.2f %d %d\n", mean, x[index], y[index]);

    return 0;
}