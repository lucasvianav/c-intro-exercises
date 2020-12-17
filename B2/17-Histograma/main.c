#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5
#define NUMBER_OF_COLORS 5

int main(){
    int *colorInPixel = (int *)malloc(WIDTH*HEIGHT * sizeof(int)); // imagem | colorInPixel[pixelIndex] = cor
    int *pixelsPerColor = (int *)malloc(NUMBER_OF_COLORS * sizeof(int)); // pixelsPerColor[color] = quantidade de pixels com aquela cor
    int color = 0; // cor mais presente no histograma (iniciada na 0)

    // zera todos os contadores de pixels das cores
    for(int i = 0; i < NUMBER_OF_COLORS; i++){ pixelsPerColor[i] = 0; }

    // recebe o input e já vai contando quantos pixels tem cada cor
    for(int i = 0; i < WIDTH*HEIGHT; i++){ 
        scanf("%d", &colorInPixel[i]);
        pixelsPerColor[colorInPixel[i]]++;
    }

    // printa o output para cada cor
    for(int i = 0; i < NUMBER_OF_COLORS; i++){
        printf("%d: |", i); // índice da cor

        // quantidade de pixels (#)
        for(int j = 0; j < pixelsPerColor[i]; j++){ printf("#"); }

        // linebreak
        printf("\n");

        // seleciona a cor mais presente no histograma
        if(pixelsPerColor[i] > pixelsPerColor[color]){ color = i; }
    }

    // printa os pixels da cor mais presente
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        if(colorInPixel[i] == color){
            printf("%d\n", i);
        }
    }

    // desaloca a memória dos vetores
    free(colorInPixel);
    free(pixelsPerColor);

    return 0;

}