#include <stdio.h>
#include <stdlib.h>

// são 12 meses
#define NUMBER_OF_MONTHS 12

int main(){
    // vetor que vai armazenar a quantidade de horas jogadas em cada mês
    // (o índice é o mês)
    double *usage = (double *)malloc(NUMBER_OF_MONTHS * sizeof(double));

    // lê o input
    for(int i = 0; i < NUMBER_OF_MONTHS; i++){ scanf("%lf", &usage[i]); }

    // inicializa o mês do output como janeiro
    int month = 0; // mês do output
    double hours = usage[month]; // horas jogadas no mês do output

    // varre todo o vetor e seleciona o mÊs com mais horas jogadas
    for(int i = 0; i < NUMBER_OF_MONTHS; i++){
        if(usage[i] > hours){
            month = i;
            hours = usage[month];
        }
    }

    // printa o resultado
    printf("%d %.2lf\n", (month+1), hours);

    // desaloca a memória do vetor
    free(usage);

    return 0;
}