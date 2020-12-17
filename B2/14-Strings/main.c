#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main(){
    char letter;
    char *string = (char *)malloc(MAX_SIZE * sizeof(char));
    int count = 0;

    // recebe input
    scanf("%c", &letter);
    scanf("%s", string);

    // varre a string e aumenta a contagem caso encontre
    // uma letra igual
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == letter){ count++; }
    }

    printf("%d\n", count);

    return 0;
}