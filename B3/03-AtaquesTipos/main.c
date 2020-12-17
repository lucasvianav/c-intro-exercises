#include <stdio.h>
#include <stdlib.h>

int main(){
    int M; // quantidade de tipos existentes no jogo
    int **attacks = (int **)malloc(sizeof(int *)); // matriz com os ataques que serão inseridos pelo jogador
    int defense; // tipo de defesa (do inimigo) no qual o ataque será usado
    int noAttacks = 0; // número de ataques recebidos
    float *chosenAttack = (float *)malloc(2 * sizeof(float)); // melhor ataque

    // recebe a ordem da matriz (M)
    scanf("%d", &M);

    // cria M linhas na matriz
    float **matrix = (float **)malloc(M * sizeof(int *));

    // recebe os elementos da matriz
    for(int i = 0; i < M; i++){
        matrix[i] = (float *)malloc(M * sizeof(int)); // cria M colunas para cada linha da matriz

        for(int j = 0; j < M; j++){ scanf("%f", &matrix[i][j]); }
    }

    // recebe os ataques (até o input -1)
    while(1){
        attacks = (int **)realloc(attacks, (noAttacks+1) * sizeof(int *)); // adiciona uma linha na matriz dos ataques

        // cada linha tem duas colunas, a primeira para o dano e a segunda para o índice
        attacks[noAttacks] = (int *)malloc(2 * sizeof(int));

        // recebe o dano
        scanf("%d", &attacks[noAttacks][0]);

        // caso o dano recebido seja diferente de -1, recebe o índice correspondente
        // caso contrário, sai do loop
        if(attacks[noAttacks][0] != -1){ scanf("%d", &attacks[noAttacks++][1]); }
        else{ break; }
    }

    // recebe o tipo da defesa
    scanf("%d", &defense);

    // chosenAttack[0] é o índice do ataque escolhido
    chosenAttack[1] = 0; // dano (considerando o modificador)
    
    // e compara com os outros para selecionar o melhor
    for(int i = 0; i < noAttacks; i++){
        if(matrix[attacks[i][1]][defense] * attacks[i][0] > chosenAttack[1]){
            chosenAttack[0] = attacks[i][1];
            chosenAttack[1] = matrix[attacks[i][1]][defense] * attacks[i][0];
        }
 
        free(attacks[i]); // libera a memória de cada linha da matriz dos ataques
    }

    // printa o resultado
    printf("O melhor ataque possui indice %.0f e dano %.2f\n", chosenAttack[0], chosenAttack[1]);

    // libera toda a memória alocada
    free(attacks[noAttacks]);
    free(attacks);
    for(int i = 0; i < M; i++){ free(matrix[i]); }
    free(matrix);
    free(chosenAttack);

    return 0;
}