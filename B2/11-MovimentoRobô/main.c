#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 200

// outra solução seria fazer D = +1, E = -1
//          NORTE 0
//  LESTE 3         OESTE 1
//          SUL 2

// vai retornar a nova direção do robô com base no comando recebido e na direção que ele apontava
char *updateDirection(char *direction, char command){
    switch(direction[0]){ // checa a primeira letra do nome da direção
        case 'N': // se ele estiver virado pro norte
            switch (command){
                case 'E': // e for virar pra esquerda
                    return "Oeste"; // vai ficar virado pro oeste
                
                case 'D': // e se for virar pra direita
                    return "Leste"; // vai ficar virado pro leste
            }
        
        case 'S': // se ele estiver virado pro sul
            switch (command){
                case 'E': // e for virado pra esquerda
                    return "Leste"; // vai ficar virado pro leste
                
                case 'D': // e for virado pra direita 
                    return "Oeste"; // vai ficar virado pro leste
            } // e assim por diante

        case 'L':
            switch (command){
                case 'E':
                    return "Norte";
                
                case 'D':
                    return "Sul";
            }

        case 'O':
            switch (command){
                case 'E':
                    return "Sul";
                
                case 'D':
                    return "Norte";
            }
    }

    return NULL;

}

int main(){
    char *commands = (char *)malloc((MAX_COMMANDS + 1) * sizeof(char)); // +1 no tamanho porque tem que incluir o \0
    char direction[] = "Norte"; // Norte, Sul, Leste, Oeste

    scanf("%s", commands); // recebe a string dos comandos

    // faz os "cálulos" da posição
    for(int i = 0; commands[i] != '\0'; i++){
        strcpy(direction, updateDirection(direction, commands[i]));
    }

    // printa o resultado
    printf("%s\n", direction);

    // desaloca a memória utilizada para os comandos
    free(commands);

    return 0;
}