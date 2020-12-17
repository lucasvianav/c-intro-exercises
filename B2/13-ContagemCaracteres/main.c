#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 20 // máximo número de caracteres na string

typedef int boolean;
#define True 1
#define False 0

int main(){
    char *string = (char *)malloc(MAX_CHARS * sizeof(char));
    int count = 0; // número de caracteres diferentes na string
    boolean isRepeated;

    // recebe o input
    scanf("%s", string);

    // faz a contagem de caracteres diferentes na string
    for(int i = 0; string[i] != '\0'; i++){
        isRepeated = False; // se a letra está repetida na string

        // checa se essa letra já foi contabilizada anteriormente
        for(int j = 0; j < i; j++){
            if(string[j] == string[i]){ 
                isRepeated = True;
                break;
            }
        }

        // se não tiver sido, incrementa a contagem
        if(!isRepeated){ count++; }
    }

    // printa o output
    printf("%d\n", count);

    // desaloca memória
    free(string);

    return 0;

}