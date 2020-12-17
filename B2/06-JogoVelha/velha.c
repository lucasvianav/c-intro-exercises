#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

#define boolean int
#define True 1
#define False 0

// função auxiliar para desalocar memória de uma matriz de char
void freeMatrix(char **matrix, int rows){
    for(int i = 0; i < rows; i++){ free(matrix[i]); }
    free(matrix);

    return;
}

int main(){
    char **matrix = (char **)malloc(ROWS * sizeof(char*)); // matriz do jogo
    boolean row, column;
    boolean mainDiagonal = True; // se alguém ganhou na diagonal principal
    boolean secDiagonal = True; // se alguém ganhou na diagonal secundária
    boolean isFull = True; // se a matriz está cheia (nenhum -)

    // recebe o input
    for(int i = 0; i < ROWS; i++){
        matrix[i] = (char *)malloc(COLS * sizeof(char)); // linhas da matriz

        for(int j = 0; j < COLS; j++){ // recebe cada elemento daquela linha
            while(True){ // loop para garantir que só vai receber x, o ou -
                scanf("%c", &matrix[i][j]);
                
                // garante que só vai receber x, o ou -
                if(matrix[i][j] == 'x' || matrix[i][j] == 'o' || matrix[i][j] == '-'){ break; }
            }

            // se houver pelo menos um element - na matriz, significa que ela não está cheia
            if(matrix[i][j] == '-'){ isFull = False; }
        }

    }

    // checa se alguém ganhou por linha
    for(int i = 0; i < ROWS; i++){ // vai de linha por linha
        row = True; // variável que indica se alguém ganhou

        for(int j = 1; j < COLS; j++){ // e de coluna por coluna (cada elemento da linha atual)
            if(matrix[i][j] != matrix[i][j-1]){ // se houverem dois elementos diferentes naquela linha
                row = False; // então não ganhou ali
                break; // e não precisa olhar o resto da linha
            }
        }

        // se todos os elementos daquela linha forem iguais e não forem -
        // então alguém ganhou naquela linha
        if(row && matrix[i][0] != '-'){
            printf("%c ganhou\n", matrix[i][0]); // printa quem ganhou

            freeMatrix(matrix, ROWS); // desaloca memória
            return 0; // e encerra a execução
        }

        // vai checando as diagonais. se houverem dois elementos diferentes nelas, então não
        // ganhou naquela diagonal
        if(i > 0 && matrix[i][i] != matrix[i-1][i-1]){ mainDiagonal = False; }
        if(i > 0 && matrix[i][COLS - i - 1] != matrix[i-1][COLS - i]){ secDiagonal = False; }
    }

    // se o elemento central (pertence às duas diagonais) não for - e os elementos de
    // de uma das diagonais forem todos iguais (e consequentemente diferentes de -)
    // signific que alguém ganhou naquela diagonal
    if(matrix[(ROWS-1)/2][(COLS-1)/2] != '-' && (mainDiagonal || secDiagonal)){
        printf("%c ganhou\n", matrix[(ROWS-1)/2][(COLS-1)/2]); // printa quem ganhou

        freeMatrix(matrix, ROWS); // desaloca memória
        return 0; // e encerra a execução
    }

    // checa se alguém ganhou nas colunas
    // o processo é análogo ao das linhas
    for(int j = 0; j < COLS; j++){ 
        column = True;

        for(int i = 1; i < ROWS; i++){
            if(matrix[i][j] != matrix[i-1][j]){
                column = False;
                break;
            }
        }

        if(column && matrix[0][j] != '-'){
            printf("%c ganhou\n", matrix[0][j]);
            
            freeMatrix(matrix, ROWS);
            return 0;
        }

    }

    // se chegou até aqui, significa que ninguém ganhou
    // há duas opções, ou empatou ou o jogo está em andamento

    // se a matriz estiver cheia (não contém nenhum -), 
    // significa que o jogo já acabou e deu empate
    if(isFull){ printf("empate\n"); }

    // se a matriz não estiver cheia, significa que o jogo
    // ainda não acabou. ou seja, está em andamento
    else{ printf("em jogo\n"); }

    // desaloca memória
    freeMatrix(matrix, ROWS);

    // e encerra a execução
    return 0;

}