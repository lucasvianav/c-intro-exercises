#include <stdio.h>
#include <stdlib.h>

#define SIZE 30+1 // 30 letters + '\0'

// encrypts the given word
char* encrypt(char letter, char *word, int *count){
    int dec = (int) letter; // ASCII value of the target letter
    char *newWord = (char *)malloc(SIZE * sizeof(char));

    // goes through the whole word
    for(int i = 0; i < SIZE; i++){
        if(word[i] == letter){ // if encounters a letter that matches the target
            (*count)++; // Increments the swap count
            newWord[i] = (char)(dec + i); // Copies the swapped letter
        }
        
        // Copies all chars that aren't == to letter
        else{ 
            newWord[i] = word[i];
        }
    }

    return newWord;
}

int main(){
    char letter; // target letter
    char *word = (char *)malloc(SIZE * sizeof(char)); // original word
    char *newWord;
    int count = 0; // number of swaps

    // receives input
    scanf("%c", &letter);
    scanf("%s", word);

    // receives new word
    newWord = encrypt(letter, word, &count);

    // prints output
    printf("Numero de trocas: %d\n", count);
    printf("Nova palavra: %s\n", newWord);
    printf("Palavra original: %s\n", word);

    // deallocates memory
    free(word);
    free(newWord);

    return 0;

}