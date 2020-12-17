#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int inputSize = 0; // input string's length
    char *input = (char *)malloc(sizeof(char)); // input name
    char aux; // auxiliar variable in order to receive each input char

    // infinite loop
    while(1){
        // reallocates the input vector in order to accommodate the new char
        input = (char *)realloc(input, ++inputSize * sizeof(char)); 

        scanf("%c", &aux); // receives the new char
        input[inputSize-1] = (aux == '\n' || aux == '\r') ? '\0' : aux; // adds it to the input array

        if(aux == '\n' || aux == '\r'){ break; } // if the new char is a linebreak, the input has finished
    }

    // allocates the ouput array (inputSize + 1 because of the comma)
    char *output = (char *)malloc((inputSize + 1) * sizeof(char)); 

    // goes through the input vector from right to left
    for(int i = inputSize - 1; i >= 0; i--){
        if(input[i-1] == ' '){ // when the last surname's first char is found
            int sep = i; // stores that index (separation between name and last surname)

            input[i-1] = '\0'; // excludes the last surname from the input array

            // copies the last surname to the output array
            while(i < inputSize){
                output[i-sep] = (input[i] != '\0') ? toupper(input[i]) : ',';
                input[i++] = '\0';
            }

            // adds a whitespace and ends the output array
            output[i - sep] = ' ';
            output[i - sep + 1] = '\0';

            strcat(output, input); // concatenates both arrays ("LASTS SURNAME, " + "name")

            break; // breaks out of the loop
        }
    }

    // prints the output
    printf("%s\n", output);

    // frees the arrays
    free(input);
    free(output);

    return 0;
}