#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// receives a string and returns an array of strings in 
// which each row contains a word
char **split(char *phrase, int *wordCounter){
    char **array = (char **)malloc(sizeof(char *)); // allocates the array of strings
    *wordCounter = 0; // number of words in the phrase and array

    // gets the first word (token) from the phrase
    char *token = strtok(phrase, " ");

    // goes through each word in the phrase
    while(token != NULL){
        array = (char **)realloc(array, ++(*wordCounter) * sizeof(char *)); // allocates a new row (word-string) to the array
        
        array[*wordCounter-1] = (char *)malloc(sizeof(char)); // and a column for that row
        int wordLength = 0; // number of letters in the word + 1 ('\0')

        // goes through each letter in the current word
        while(1){
            // allocates a new column (letter) to the row (word)
            array[*wordCounter - 1] = (char *)realloc(array[*wordCounter - 1], ++wordLength * sizeof(char)); 

            // copies the phrases' word to the array's row (word)
            array[*wordCounter - 1][wordLength - 1] = token[wordLength - 1];

            // breaks out of the loop when the word ends
            if(token[wordLength - 1] == '\0'){ break; }
        }

        // gets the next word (token)
        token = strtok(NULL, " ");
    }

    return array;
}

// prints the array
void print(char **array, int length){
    // goes through each row and prints it
    for(int i = 0; i < length; i++){ printf("%s\n", array[i]); }
    return;
}

// insertion sorts the words alphabetically
void sort(char **array, int length){
    char *aux; // Auxiliar variable to store the "current" element

    // Loops through the whole vector
    for(int i = 0; i < length; i++){
        aux = (char *)malloc(sizeof(char)); // allocates the aux variable

        // current word's length
        int length = strlen(array[i]) + 1; 

        // copies the current word to aux while lowering it
        for(int k = 0; k < length; k++){
            aux = (char *)realloc(aux, (k + 1) * sizeof(char));
            aux[k] = tolower(array[i][k]);
        }

        // Goes through the already passed part of the vector
        // And takes the "current" element as far left as needed
        int j = i - 1; // the current word goes one position back (new "current" position)
        while(j >= 0 && strcmp(aux, array[j]) < 0){
            free(array[j + 1]); // deletes the word in the "next" position
            array[j + 1] = (char *)malloc(sizeof(char)); // and allocates it once more

            // word previously in the "current" position's length
            length = strlen(array[j]) + 1;

            // copies the word previously in the "current" position to the "next" position
            for(int k = 0; k < length; k++){
                array[j + 1] = (char *)realloc(array[j + 1], (k + 1) * sizeof(char));
                array[j + 1][k] = array[j][k];
            }
            
            // goes back another position
            j--;
        }
        
        // at this point, the correct position to the current word was found
        // all that's left is to copy it to that position
        
        // deletes whatever's in that position
        free(array[j + 1]);
        array[j + 1] = (char *)malloc(sizeof(char)); // and allocates it again

        // current word's length
        length = strlen(aux) + 1;

        // copies the current word to it's new position
        for(int k = 0; k < length; k++){
            array[j + 1] = (char *)realloc(array[j + 1], (k + 1) * sizeof(char));
            array[j + 1][k] = aux[k];
        }

        // frees the auxiliar variable
        free(aux);
    }

    return;
}

int main(){
    int phraseSize = 0; // number of words in the phrase
    char *phrase = (char *)malloc(sizeof(char)); // input phrase
    char aux; // auxiliar variable in order to receive the input chars
    int wordCount, operation;

    // receives the input
    while(1){
        phrase = (char *)realloc(phrase, ++phraseSize * sizeof(char));

        scanf("%c", &aux);
        phrase[phraseSize-1] = (aux == '\n' || aux == '\r') ? '\0' : aux;

        if(aux == '\n' || aux == '\r'){ break; }
    }

    // receives the desired operation
    scanf("%d", &operation);

    // operate
    char **array = split(phrase, &wordCount);
    if(operation == 2){ sort(array, wordCount); }

    // prints the output
    print(array, wordCount);

    // frees the vectors
    for(int i = 0; i < wordCount; i++){ free(array[i]); }
    free(array);
    free(phrase);

    return 0;    
}