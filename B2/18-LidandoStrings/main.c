#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

int main(){
    char *firstString = (char *)malloc(MAX_SIZE * sizeof(char)); // primeira palavra
    char *secondString = (char *)malloc(MAX_SIZE * sizeof(char)); // segunda palavra

    // recebe o input das palavras
    scanf("%s", firstString);
    scanf("%s", secondString);

    if(!strcmp(firstString, secondString)){
        printf("iguais\n");
    }

    else{
        if(strlen(firstString) + strlen(secondString) > MAX_SIZE){
            firstString = (char *)realloc(firstString, (strlen(firstString) + strlen(secondString)) * sizeof(char));
        }

        strcat(firstString, secondString);

        printf("%s\n", firstString);
    }

    free(firstString);
    free(secondString);

    return 0;
}