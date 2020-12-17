#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // palavra tabu
    char tabu[21]; 

    // array auxiliar para comparar com a palavra tabu
    char aux[21]; 

    // frase
    char *phrase = (char *)malloc(1); 

    // variável temporária na qual será armazenado cada caractere lido da frase
    char tmp; 

    // índice auxiliar para comparar com a palavra tabu
    int i = -1; 

    // índice da último espaço de char da frase
    int k = 0; 

    // quantidade de vezes que a palavra tabu foi encontrada
    int count = 0; 

    // recebe a palavra tabu
    scanf("%s\n", tabu);

    // recebe cada caractere da frase, até o $
    while(1){
        // recebe um caractere da frase
        scanf("%c", &tmp);

        // se o caractere recebido for igual ao primeiro caractere da palavra 
        // chave, armazena ele na primeira posição do array aux
        // depois vai receber outro caractere e comparar com o segundo, depois
        // com o terceiro, e assim por diante, de um por um.
        if(tmp == tabu[i+1]){ aux[++i] = tmp; }

        // quando inevitavelmente um caractere que não é igual ao da palavra
        // tabu (mesmo que a atual palavra seja a última, o caractere final $
        // não está incluso na palavra tabu)
        else{
            // caso o array auxiliar possua a mesma quantidade de caracteres
            // da palavra tabu, significa que são iguais, ou seja, a palavra
            // tabu foi encontrada na frase
            if(i + 1 == strlen(tabu)){ 
                count++; // nesse caso, basta incrementar o contador
                i = -1; // e resetar o índice auxiliar para o valor inicial
                // (sem incluir essa palavra na frase)
            }

            // caso contrário, há duas possibilidades:
            // ou uma palavra que começava com vários caracteres iguais
            // aos da palavra tabu está sendo inserida (nesse caso, i
            // vai ter um valor diferente do inicial, >= 0, e os caracteres
            // que foram salvos no array auxiliar precisam ser incluidos na frase)
            // ou apenas caracteres que diferm da primeira letra da palavra
            // tabu foram inseridas (nesse caso, i vai possuir o valor inicial, -1,
            // e não há caracteres além de tmp que precisam ser incluidos na frase)

            // na primeira possibilidade supracitada
            else if(i > -1){
                // passa todos os caracteres da array auxiliar
                // para a frase
                for(int j = 0; j < i + 1; j++){
                    phrase = (char *)realloc(phrase, k + 1);
                    phrase[k++] = aux[j];        
                }

                // reseta o índice auxiliar para o valor inicial
                i = -1;
            }

            // caso tmp (o último caractere lido) seja igual
            // ao primeiro caractere da palavra tabu, salva ele
            // no array auxiliar e passa pra próxima iteração do loop
            if(tmp == tabu[i+1]){ 
                aux[++i] = tmp;
                continue;
            }

            
            phrase = (char *)realloc(phrase, k + 1); // realoca memória pra mais um caractere na frase
            phrase[k++] = (tmp == '$') ? '\0' : tmp; // salva o caractere na frase (ou \0, caso seja o $)

            if(tmp == '$'){ break; } // se a frase tiver terminado, quebra o loop
        }
    }

    // printa o resultado
    printf("A palavra tabu foi encontrada %d vezes\n", count);
    printf("Frase: %s\n", phrase);

    // desaloca a memória da frase
    free(phrase);

    return 0;
}